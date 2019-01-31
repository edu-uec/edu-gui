#include "commandmodel.h"

using namespace std;

CommandModel::CommandModel(QObject* parent) :
    QAbstractListModel (parent),
    mDb(DatabaseManager::instance()),
    mCommands(mDb.commandDao.commands())
{
}

QModelIndex CommandModel::addCommand(const Command &command)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    unique_ptr<Command> newCommand(new Command(command));
    mDb.commandDao.addCommand(*newCommand);
    mCommands->push_back(move(newCommand));
    endInsertRows();
    //emit dataChanged(index(rowIndex), index(rowIndex));
    return index(rowIndex, 0);
}

int CommandModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mCommands->size();
}

QVariant CommandModel::data(const QModelIndex& index, int role) const
{
    if(!isIndexValid(index)) {
        return QVariant();
    }
    const Command& command = *mCommands->at(index.row());

    switch(role){
        case Roles::IdRole:
            return command.id();

        case Roles::NameRole:
        case Qt::DisplayRole:
            return command.name();
        default:
            return QVariant();
    }
}

bool CommandModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!isIndexValid(index)
            || role != Roles::NameRole) {
        return false;
    }
    Command& command = * mCommands->at(index.row());
    command.setName(value.toString());
    mDb.commandDao.updateCommand(command);
    //emit dataChanged(index, index);
    return true;
}

bool CommandModel::removeRows(int row, int count, const QModelIndex&parent)
{
    if (row < 0
            || row >= rowCount()
            || count < 0
            || (row + count) > rowCount()) {
        return false;
    }
    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while (countLeft--){
        const Command& command = *mCommands->at(row + countLeft);
        mDb.commandDao.removeCommand(command.id());
    }
    mCommands->erase(mCommands->begin() + row,
                   mCommands->begin() + row + count);
    endRemoveRows();
    emit dataChanged(index(row), index(row));
    return true;
}

QHash<int, QByteArray> CommandModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    return roles;
}

bool CommandModel::isIndexValid(const QModelIndex &index) const
{
    if (index.row() < 0
            || index.row() >= rowCount()
            || !index.isValid()) {
        return false;
    }
    return true;
}

void CommandModel::addCommandFromName(const QString &name)
{
    addCommand(Command(name));
}
