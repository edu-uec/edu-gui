#include "commandinterpreter.h"
#include "commandmodel.h"
#include "simpleserial.h"

CommandInterpreter* CommandInterpreter::instance = nullptr;

CommandInterpreter* CommandInterpreter::getInstance(CommandModel& commandModel)
{
    if (instance == nullptr)
        {
            instance = new CommandInterpreter(commandModel);
        }
        return instance;
}

CommandInterpreter::CommandInterpreter(CommandModel& commandModel)
{
    commandModel_ = &commandModel;
}

void CommandInterpreter::onCommandArrive(std::string command){
    std::cout << command << std::endl;
    commandModel_->addCommandFromName(command.c_str());

    std::string portName = "/dev/cu.usbmodem145301";
    SimpleSerial serialPortInstance(portName, 115200);

    if(command == "w_000右"){
        serialPortInstance.writeString("r");
    }
    else if(command == "w_001左"){
        serialPortInstance.writeString("l");
    }
    else if(command == "w_004前"){
        serialPortInstance.writeString("f");
    }
    else if(command == "w_008止"){
        serialPortInstance.writeString("s");
    }
}


