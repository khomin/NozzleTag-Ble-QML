#include "bleModelItem.h"

BleModelItem::BleModelItem(const QString devName, const QString devAddr) {
    this->m_devName = devName;
    this->m_devAddr = devAddr;
}

QString BleModelItem::getDevName() const {
    return m_devName;
}

QString BleModelItem::getDevAddr() const {
    return m_devAddr;
}
