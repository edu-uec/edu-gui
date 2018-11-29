#ifndef CPPSIGNALSLOT_H
#define CPPSIGNALSLOT_H
#include <QObject>
#include <QVariant>

class CppSignalSlot : public QObject
{
    Q_OBJECT
public:
    explicit CppSignalSlot(QObject *parent = std::nullptr_t());

//シグナル
signals:
    void cppSignal(QVariant text);

//スロット
public slots:
    void cppSlots(QString msg);

};

#endif // CPPSIGNALSLOT_H
