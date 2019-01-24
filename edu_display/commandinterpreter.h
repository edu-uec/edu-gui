#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include<QObject>
#include<QString>
#include<QVariant>
#include<vector>
#include<iostream>
#include <thread>
#include <unistd.h>
#include <list>

using namespace std;

class CommandModel;

class CommandInterpreter
{
private:
    static CommandInterpreter* instance;
    CommandModel* commandModel_;
    CommandInterpreter(CommandModel& commandModel);
    vector<string> orders;
public:
    static CommandInterpreter* getInstance(CommandModel& commandModel);
    void onCommandArrive(std::string command);
};

#endif // COMMANDINTERPRETER_H
