#include "bleModel.h"

BleModel::BleModel(QObject *parent) {

}

void BleModel::addBle(const BleModelItem *bleItem) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    bleDevices.push_back((BleModelItem*)bleItem);
    endInsertRows();
}

int BleModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return bleDevices.count();
}

QVariant BleModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= bleDevices.count())
        return QVariant();

    const BleModelItem* ble_dev= bleDevices[index.row()];
    if (role == RoleName)
        return ble_dev->getDevName();
    else if (role == RoleAddr)
        return ble_dev->getDevAddr();
    else  if (role == RoleRssi)
        return ble_dev->getRssi();
    return QVariant();
}

QHash<int, QByteArray> BleModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[RoleName] = "devName";
    roles[RoleAddr] = "devAddr";
    roles[RoleRssi] = "devRssi";
    return roles;
}
