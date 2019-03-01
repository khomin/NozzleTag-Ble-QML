#include "bleModelItem.h"

BleModelItem::BleModelItem(const QString devName,
                           const QString devAddr,
                           const int rssi,
                           const QBluetoothDeviceInfo & info,
                           DeviceInfo * customInfo) {
    this->m_custom_info = customInfo;
    this->m_dev_info = info;
    this->m_devName = devName;
    this->m_devAddr = devAddr;
    this->m_rssi = rssi;
}

QString BleModelItem::getDevName() const {
    return m_devName;
}

QString BleModelItem::getDevAddr() const {
    return m_devAddr;
}

int BleModelItem::getRssi() const {
    return m_rssi;
}

QBluetoothDeviceInfo & BleModelItem::getDevInfo() {
    return m_dev_info;
}

DeviceInfo* BleModelItem::getDevCustomInfo() const {
    return m_custom_info;
}
