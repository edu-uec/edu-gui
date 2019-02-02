#ifndef PROGRAMRUNNER_H
#define PROGRAMRUNNER_H

#include <QObject>
#include <unordered_map>
#include <string>
#include "simpleserial.h"

class CommandModel;
class JuliusOrderInterpreter;

class ProgramRunner : public QObject
{
    Q_OBJECT
public:
    explicit ProgramRunner(QObject *parent = std::nullptr_t());
    static void initialize(CommandModel* commandModel);
    void runProgram(JuliusOrderInterpreter *orderInterpreter);
    std::string portName;
private:
    static CommandModel* mCommandModel;
    std::unordered_map<std::string, std::string> arduinoCommandMap;
    std::unique_ptr<SimpleSerial> serialPortInstance;
};

#endif // PROGRAMRUNNER_H
