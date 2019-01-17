#include "commanddao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "command.h"
#include "databasemanager.h"

using namespace std;

CommandDao::CommandDao(QSqlDatabase& database) :
    mDatabase(database)
{
}

void CommandDao::init() const
{
    if (!mDatabase.tables().contains("commands")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE commands (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
        DatabaseManager::debugQuery(query);
    }
}

void CommandDao::addCommand(Command &command) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO commands (name) VALUES (:name)");
    query.bindValue(":name", command.name());
    query.exec();
    command.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
}

void CommandDao::updateCommand(const Command &command) const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE commands SET name = (:name) WHERE id + (:id)");
    query.bindValue(":name", command.name());
    query.bindValue(":id", command.id());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void CommandDao::removeCommand(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM commands WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

unique_ptr<vector<unique_ptr<Command>>> CommandDao::commands() const
{
    QSqlQuery query("SELECT * FROM albums", mDatabase);
    query.exec();
    unique_ptr<vector<unique_ptr<Command>>> list(new vector<unique_ptr<Command>>());
    while(query.next()) {
        unique_ptr<Command> command(new Command());
        command->setId(query.value("id").toInt());
        command->setName(query.value("name").toString());
        list->push_back(move(command));
    }
    return list;
}
