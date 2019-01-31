#ifndef ORDERPROGRAM_H
#define ORDERPROGRAM_H

#include<QObject>
#include<QString>
#include<QVariant>
#include<vector>
#include<iostream>
#include <thread>
#include <unistd.h>
#include <list>

using namespace std;

class OrderProgram : public QObject
{
    Q_OBJECT
public:
    atomic_bool isRunProgram;

    explicit OrderProgram(QObject *parent = std::nullptr_t()) : QObject(parent){
        isRunProgram = false;
    }

    Q_INVOKABLE QString getOrderName(int index) const{
        return static_cast<unsigned long>(index) < orders.size() ? QString::fromStdString(orders[static_cast<unsigned long>(index)]) : "error";
    }

    Q_INVOKABLE void doOrder(int index) const{
        std::cout << index << std::endl;
    }

    void onCommandArrive(std::string command){
//        std::cout << command << std::endl;
//        emit pushOrderSignal(QString::fromStdString(command));

        std::cout << command << std::endl;

        char commandType = command[0];
        int commandId = std::stoi(command.substr(2, 3));
        auto commandName = command.substr(5).c_str();

        std::cout << "type:" << commandType << " id:" << commandId << " name:"<< commandName << std::endl;


        std::string portName = "/dev/cu.usbmodem145301";
        //SimpleSerial serialPortInstance(portName, 115200);

        if(commandType == 'w'){
            commandModel_->addCommandFromName(commandName);
            commandModel_->submit();
            switch (commandId) {
                case 0: //w_000みぎをむく
    //              serialPortInstance.writeString("r");
                break;
            }
        }
        else if(commandType == 'c'){
            if(commandId == 0){//実行
                commandModel_->addCommandFromName(commandName);
            }
            else if(commandId == 1){//消去
                commandModel_->removeRows(commandModel_->rowCount()-1, 1);
            }
            else if(commandId == 2){//中止
                commandModel_->addCommandFromName(commandName);
            }
            else if(commandId == 3){//一つ戻る
                commandModel_->addCommandFromName(commandName);
            }

        }
    }

    void runOrderProgram(){
        for(string& order : orders){
            if(!isRunProgram) {break;}
            std::cout << "run: " << order << std::endl; //送信処理
            emit changeOrderBlockColorSignal(0, "#ff0000");
            std::chrono::milliseconds time(2000);
            std::this_thread::sleep_for(time);
        }


        isRunProgram = false;
        std::cout << "program finished! " << std::endl;
    }

signals:
    void pushOrderSignal(QVariant text);
    void deleteOrderSignal();
    void changeOrderBlockColorSignal(QVariant index, QVariant color);

private:
    vector<string> orders;
};



#endif // ORDERPROGRAM_H
