#include "programrunner.h"
#include "commandmodel.h"
#include "juliusOrderInterpreter.h"

#include <QString>
#include <QThread>
#include <iostream>

ProgramRunner::ProgramRunner(QObject *parent) : QObject(parent)
{
    arduinoCommandMap["みぎをむく"] = "r";
    arduinoCommandMap["ひだりをむく"] = "l";
    arduinoCommandMap["まえにすすむ"] = "f";
    arduinoCommandMap["うしろにすすむ"] = "b";
    arduinoCommandMap["とまる"] = ""; //Do nothing
    arduinoCommandMap["Go"] = ""; //Do nothing

    //serialPortInstance.reset(new SimpleSerial(portName, 115200));
}

void ProgramRunner::initialize(CommandModel* commandModel)
{
    mCommandModel = commandModel;
}

void ProgramRunner::runProgram(JuliusOrderInterpreter *orderInterpreter)
{
    if(mCommandModel == nullptr)
    {
        std::cerr << "\"ProgramRunner\" Class not initialized with \"CommandModel\" pointer" << std::endl;
        return;
    }
    for(int i=0; i < mCommandModel->rowCount(); ++i)
    {
        QString name = mCommandModel->data(mCommandModel->index(i), 258).toString();
        std::cout << name.toStdString() << std::endl;
        orderInterpreter->setListviewCurrentIndex(i);
        //serialPortInstance->writeString(arduinoCommandMap[name.toStdString()]);
        QThread::sleep(1);
    }
}

CommandModel* ProgramRunner::mCommandModel = nullptr;
