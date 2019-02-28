#include "bleModel.h"

BleModel::BleModel(QObject *parent) {
    roleNameMapping[RoleName] = "devName";
    roleNameMapping[RoleAddr] = "devAddr";
    roleNameMapping[RoleRssi] = "devRsii";
}

void BleModel::appendBleDevice(const BleModelItem *bleItem) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    bleDevices.push_back((BleModelItem*) std::move(bleItem));
    endInsertRows();
}

int BleModel::getCountDevices() {
    return bleDevices.count();
}

int BleModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return bleDevices.count();
}

void BleModel::clearAll() {
    if(!bleDevices.isEmpty()) {
        removeRows(rowCount()-1, 1, QModelIndex());
    }
}

bool BleModel::removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) {
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    while (count--) delete bleDevices.takeAt(row);
    endRemoveRows();
    return true;
}

QList<BleModelItem*>& BleModel::getBleDevices() {
    return bleDevices;
}

QVariant BleModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= bleDevices.count())
        return QVariant();

    const BleModelItem* ble_dev = bleDevices[index.row()];
    if (role == RoleName)
        return ble_dev->getDevName();
    else if (role == RoleAddr)
        return ble_dev->getDevAddr();
    else  if (role == RoleRssi)
        return ble_dev->getRssi();
    return QVariant();
}

QHash<int, QByteArray> BleModel::roleNames() const {
    return roleNameMapping;
}
