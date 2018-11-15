#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "cppsignalslot.h"
#include "orderdata.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    CppSignalSlot obj;
     //Get an access to root object and qml object by object defined in main.qml
    QObject *root = engine.rootObjects().first();

    //シグナル・スロット接続
    //QObject::connect(const QObject *sender, PointerToMemberFunction signal, const QObject *receiver, PointerToMemberFunction slot, Qt::ConnectionType type )
    QObject::connect(root, SIGNAL(qmlSignal(QString)), &obj, SLOT(cppSlots(QString)));
    QObject::connect(&obj, SIGNAL(cppSignal(QVariant)), root, SLOT(showBlock(QVariant)));

    //qmlにオブジェクトを渡す
    orderdata odata;
    engine.rootContext()->setContextProperty("orderdata", &odata);

    return app.exec();
}
