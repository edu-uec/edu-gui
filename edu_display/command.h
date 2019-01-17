#ifndef COMMAND_H
#define COMMAND_H

#include <QString>

class Command
{
public:
    explicit Command(const QString& name = "");

    int id() const;
    void setId(int id);
    QString name() const;
    void setName(const QString& name);

private:
    int mId;
    QString mName;
};

#endif // COMMAND_H
