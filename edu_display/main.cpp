#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "cppsignalslot.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    CppSignalSlot obj;
    QObject *root = engine.rootObjects().first();

    QObject::connect(root, SIGNAL(qmlSignal(QString)), &obj, SLOT(cppSlots(QString)));
    QObject::connect(&obj, SIGNAL(cppSignal(QVariant)), root, SLOT(showBlock(QVariant)));

    return app.exec();
}
