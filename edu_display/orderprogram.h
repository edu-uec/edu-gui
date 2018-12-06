#ifndef ORDERPROGRAM_H
#define ORDERPROGRAM_H

#include<QObject>
#include<QString>
#include<QVariant>
#include<vector>
#include<iostream>
#include <thread>

using namespace std;

class OrderProgram : public QObject
{
    Q_OBJECT
public:
    bool isRunProgram = false;

    explicit OrderProgram(QObject *parent = std::nullptr_t());

    Q_INVOKABLE QString getOrderName(int index) const{
        return index < orders.size() ? orders[index] : "error";
    }

    Q_INVOKABLE void doOrder(int index) const{
        std::cout << index << std::endl;
    }

    void onCommandArrive(std::string command){
        std::cout << command << std::endl;
        if(!isRunProgram){
            if(command[0] == 'w'){
            QString sCommand = QString::fromStdString(command);
            orders.push_back(sCommand);

            emit pushOrderSignal(sCommand);
            }else{
                int id = std::atoi(command.substr(2, 3).c_str());
                std::cout << "id: " << id << std::endl;
                switch (id) {
                    case 0: { //c_000実行
//                        isRunProgram = true;
//                        auto tRunOrderProgram = std::thread([this]{runOrderProgram();});
//                        tRunOrderProgram.join();

                        break;
                    }
                    case 1: //c_001消去
                    case 3: //c_003一つ戻る
                        orders.pop_back();
                        emit deleteOrderSignal();
                    break;

                }
            }
        }else{
            if(command[0] == 'c'){
                int id = std::atoi(command.substr(2, 3).c_str());
                std::cout << "id: " << id << std::endl;
                switch (id) {
                    case 0: //c_000実行
                        isRunProgram = false;
                    break;

                }
            }
        }

    }

    void runOrderProgram(){
        for(QString& order : orders){
            if(!isRunProgram) {break;}
            std::cout << order.toStdString() << std::endl;

        }
    }

signals:
    void pushOrderSignal(QVariant text);
    void deleteOrderSignal();

private:
    vector<QString> orders;
};



#endif // ORDERPROGRAM_H
