#include "bleModelDevice.h"

BleModelDevice::BleModelDevice(QObject *parent) {
    roleNameMapping[RoleName] = "devName";
    roleNameMapping[RoleAddr] = "devAddr";
    roleNameMapping[RoleRssi] = "devRsii";
    roleNameMapping[RoleAccelX] = "accelX";
    roleNameMapping[RoleAccelY] = "accelY";
    roleNameMapping[RoleAccelZ] = "accelZ";
}

void BleModelDevice::appendBleDevice(std::shared_ptr<BleModelDeviceItem> bleItem) {
    for(auto i: bleDevices) {
        if(bleItem->getDevAddr() == bleItem->getDevAddr()) {
            i = bleItem;
            QModelIndex index = createIndex(0,0);
            emit dataChanged(index, index);
            return;
        }
    }
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    bleDevices.push_back(std::move(bleItem));
    endInsertRows();
}

int BleModelDevice::getCountDevices() {
    return bleDevices.count();
}

int BleModelDevice::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return bleDevices.count();
}

void BleModelDevice::clearAll() {
    if(!bleDevices.isEmpty()) {
        removeRows(rowCount()-1, 1, QModelIndex());
    }
}

bool BleModelDevice::removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) {
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    while (count--) {
        bleDevices.takeAt(row);
    }
    endRemoveRows();
    return true;
}

QList<std::shared_ptr<BleModelDeviceItem>>& BleModelDevice::getBleDevices() const {
    return bleDevices;
}

QVariant BleModelDevice::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= bleDevices.count())
        return QVariant();

    const BleModelDeviceItem* ble_dev = bleDevices[index.row()].get();
    if (role == RoleName)
        return ble_dev->getDevName();
    else if (role == RoleAddr)
        return ble_dev->getDevAddr();
    else  if (role == RoleRssi)
        return ble_dev->getRssi();
    else  if (role == RoleAccelX)
        return ble_dev->getAccelX();
    else  if (role == RoleAccelY)
        return ble_dev->getAccelY();
    else  if (role == RoleAccelZ)
        return ble_dev->getAccelZ();
    return QVariant();
}

QHash<int, QByteArray> BleModelDevice::roleNames() const {
    return roleNameMapping;
}
