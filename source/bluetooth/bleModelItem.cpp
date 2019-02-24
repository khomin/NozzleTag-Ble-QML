#include "bleModelItem.h"

BleModelItem::BleModelItem(const QString devName, const QString devAddr, const int rssi) {
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
