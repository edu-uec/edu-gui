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
        std::cout << command << std::endl;
        if(!isRunProgram){
            if(command[0] == 'w'){
            orders.push_back(command.substr(2,3));
            emit pushOrderSignal(QString::fromStdString(command));
            }else{
                int id = std::atoi(command.substr(2, 3).c_str());
                std::cout << "id: " << id << std::endl;
                switch (id) {
                    case 0:{ //c_000実行
                        isRunProgram = true;
                        auto tRunOrderProgram = std::thread([this]{runOrderProgram();});
                        tRunOrderProgram.detach();
                        break;
                    }
                    case 1: //c_001消去
                    case 3: //c_003一つ戻る
                    if(!orders.empty()){
                        orders.pop_back();
                        emit deleteOrderSignal();
                    }
                    break;
                }
            }
        }else{
            if(command[0] == 'c'){
                int id = std::atoi(command.substr(2, 3).c_str());
                std::cout << "id: " << id << std::endl;
                switch (id) {
                    case 2: //c_002中止
                        isRunProgram = false;
                    break;
                }
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
