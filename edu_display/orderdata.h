#ifndef ORDERDATA_H
#define ORDERDATA_H

#include <QObject>
#include <QString>

class orderdata: public QObject
{
    Q_OBJECT
public:
    orderdata();

    Q_INVOKABLE QString getOrderName(int index) const{
        return orderData[index];
    }

private:
    QString orderData[8]{"a", "b", "c", "d", "e", "f", "g", "h"};
};

#endif // ORDERDATA_H
