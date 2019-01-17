#include "command.h"

Command::Command(const QString& name) :
    mId(-1),
    mName(name)
{
}

int Command::id() const
{
    return mId;
}

void Command::setId(int id)
{
    mId = id;
}

QString Command::name() const
{
    return mName;
}

void Command::setName(const QString& name)
{
    mName = name;
}
