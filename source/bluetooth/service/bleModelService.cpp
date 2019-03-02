#include "bleModelService.h"

BleModelService::BleModelService(QObject *parent) {
    m_role_mame_mapping[RoleName] = "serviceName";
    m_role_mame_mapping[RoleUuid] = "serviceUuid";
    m_role_mame_mapping[RoleValueHex] = "serviceHex";
    m_role_mame_mapping[RoleValueAsci] = "serviceAsci";
}

void BleModelService::appendBleService(const BleModelServiceItem *bleItem) {
    for(auto i: m_ble_services) {
        if(i->getUuid() == bleItem->getUuid()) {
            beginInsertRows(QModelIndex(), rowCount(), rowCount());
            i = (BleModelServiceItem*) bleItem;
            endInsertRows();
            return;
        }
    }

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_ble_services.push_back(const_cast<BleModelServiceItem*>(std::move(bleItem)));
    endInsertRows();
}

int BleModelService::getCountDevices() {
    return m_ble_services.count();
}

int BleModelService::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_ble_services.count();
}

void BleModelService::clearAll() {
    if(!m_ble_services.isEmpty()) {
        removeRows(rowCount()-1, 1, QModelIndex());
    }
}

bool BleModelService::removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) {
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    while (count--) delete m_ble_services.takeAt(row);
    endRemoveRows();
    return true;
}

QList<BleModelServiceItem*>& BleModelService::getBleService() {
    return m_ble_services;
}

QVariant BleModelService::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_ble_services.count())
        return QVariant();

    const BleModelServiceItem* p = m_ble_services[index.row()];
    if (role == RoleName)
        return p->getName();
    else if (role == RoleUuid)
        return p->getUuid();
    else  if (role == RoleValueHex)
        return p->getValueAsci();
    return QVariant();
}

QHash<int, QByteArray> BleModelService::roleNames() const {
    return m_role_mame_mapping;
}
