#include "AnimalModel.h"

AnimalModel::AnimalModel(QObject *parent) {

}

void AnimalModel::addAnimal(const Animal * animal)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_animals.push_back((Animal*)animal);
    endInsertRows();
}

int AnimalModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_animals.count();
}

QVariant AnimalModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_animals.count())
        return QVariant();

    const Animal * animal = m_animals[index.row()];
    if (role == TypeRole)
        return animal->type();
    else if (role == SizeRole)
        return animal->size();
    return QVariant();
}

QHash<int, QByteArray> AnimalModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[SizeRole] = "size";
    return roles;
}
