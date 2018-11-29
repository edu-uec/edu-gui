#ifndef ORDERPROGRAM_H
#define ORDERPROGRAM_H

#include<QObject>
#include<QString>
#include<list>

class orderProgram : public QObject
{
    Q_OBJECT
public:
    orderProgram();

    Q_INVOKABLE QString getOrderName(int index) const{
        return orderData[index];
    }

    Q_INVOKABLE void doOrder(int index) const{

    }

private:
    std::list<QString> orders;
    QString orderData[8]{"a", "b", "c", "d", "e", "f", "g", "h"};
};

#endif // ORDERPROGRAM_H
