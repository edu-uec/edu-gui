#include "commandinterpreter.h"
#include "commandmodel.h"
#include "simpleserial.h"

CommandInterpreter* CommandInterpreter::instance = nullptr;

CommandInterpreter* CommandInterpreter::getInstance(CommandModel* commandModel)
{
    if (instance == nullptr)
        {
            instance = new CommandInterpreter(commandModel);
        }
        return instance;
}

CommandInterpreter::CommandInterpreter(CommandModel* commandModel)
{
    commandModel_ = commandModel;
}

void CommandInterpreter::onCommandArrive(std::string command){
    std::cout << command << std::endl;

    char commandType = command[0];
    int commandId = std::stoi(command.substr(2, 3));
    auto commandName = command.substr(5).c_str();

    std::cout << "type:" << commandType << " id:" << commandId << " name:"<< commandName << std::endl;


    std::string portName = "/dev/cu.usbmodem145301";
    //SimpleSerial serialPortInstance(portName, 115200);

    if(commandType == 'w'){
        commandModel_->addCommandFromName(commandName);
//        switch (commandId) {
//            case 0: //w_000みぎをむく
//              serialPortInstance.writeString("r");
//            break;
//        }
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

//    if(command == "w_000"){
//        serialPortInstance.writeString("r");
//    }
//    else if(command == "w_001"){
//        serialPortInstance.writeString("l");
//    }
//    else if(command == "w_004前"){
//        serialPortInstance.writeString("f");
//    }
//    else if(command == "w_008止"){
//        serialPortInstance.writeString("s");
//    }



}


