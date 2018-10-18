#include "cppsignalslot.h"
#include <QDebug>

CppSignalSlot::CppSignalSlot(QObject *parent): QObject(parent)
{

}

void CppSignalSlot::cppSlots(QString msg) {
    qDebug() << "cpp slot is called with message: " << msg;
    emit cppSignal("a");
}
