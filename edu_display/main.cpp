#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QDebug>

#include <iostream>
#include <thread>
#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>

#include "unix_socket_server.hpp"
#include "cppsignalslot.h"
#include "juliusOrderInterpreter.h"

#include "commandmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    CommandModel commandModel;

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    context->setContextProperty("commandModel", &commandModel);
    //サーバースレッドのsignalとCommandmodel::addCommandFromName()のconnection
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

     //Get an access to root object and qml object by object defined in main.qml
    QObject *root = engine.rootObjects().first();


    asio::io_service io_service;
    unlink("/tmp/unix_socket_test");
    UnixSocketServer unixSocketServer1(io_service);
    JuliusOrderInterpreter orderInterpreter;
    unixSocketServer1.commandArriveEvent.connect(boost::bind(&JuliusOrderInterpreter::onCommandArrive, &orderInterpreter, _1));
    std::thread threadServer([&unixSocketServer1]{
        unixSocketServer1.accept();
        while (true){
            unixSocketServer1.read();
        }
    });

//    std::thread threadArduino([]{

//    });



    //シグナル・スロット接続
    //QObject::connect(const QObject *sender, PointerToMemberFunction signal, const QObject *receiver, PointerToMemberFunction slot, Qt::ConnectionType type )
//    QObject::connect(root, SIGNAL(qmlSignal(QString)), &obj, SLOT(cppSlots(QString)));
//    QObject::connect(&obj, SIGNAL(cppSignal(QVariant)), root, SLOT(addBlock(QVariant)));
      QObject::connect(&orderInterpreter, SIGNAL(pushOrderSignal(QVariant)), root, SLOT(addBlock(QVariant)));
      QObject::connect(&orderInterpreter, SIGNAL(deleteOrderSignal()), root, SLOT(deleteBlock()));
      QObject::connect(&orderInterpreter, SIGNAL(changeTextPage(QVariant)), root, SLOT(changeContentsByJuliusOI(QVariant)));
      QObject::connect(&orderInterpreter, SIGNAL(setListviewCurrentIndex(QVariant)), root, SLOT(setListviewCurrentIndex(QVariant)));


    //qmlにオブジェクトを渡す
//    engine.rootContext()->setContextProperty("JuliusOrderInterpreter", &orderInterpreter);

    return app.exec();
}
