#ifndef COMMANDDAO_H
#define COMMANDDAO_H

#include <memory>
#include <vector>

class QSqlDatabase;
class Command;

class CommandDao
{
public:
    CommandDao(QSqlDatabase& database);
    void init() const;

    void addCommand(Command& command) const;
    void updateCommand(const Command& command) const;
    void removeCommand(int id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Command>>> commands() const;

private:
    QSqlDatabase& mDatabase;
};

#endif // COMMANDDAO_H
