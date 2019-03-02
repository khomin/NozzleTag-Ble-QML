#include "bleModelDeviceItem.h"

BleModelDeviceItem::BleModelDeviceItem(const QString devName,
                           const QString devAddr,
                           const int rssi,
                           const QBluetoothDeviceInfo & info,
                           DeviceInfo * customInfo) {
    this->m_custom_info = customInfo;
    this->m_dev_info = info;
    this->m_devName = devName;
    this->m_devAddr = devAddr;
    this->m_rssi = rssi;
    this->m_accelX = "0";
    this->m_accelY = "0";
    this->m_accelZ = "0";
}

void BleModelDeviceItem::setDevName(const QVariant val) {
    m_devName = val;
}

void BleModelDeviceItem::setDevAddr(const QVariant val) {
    m_devAddr = val;
}

void BleModelDeviceItem::setRssi(const QVariant val) {
    m_rssi = val;
}

void BleModelDeviceItem::setAccelX(const QVariant val) {
    m_accelX = val;
}

void BleModelDeviceItem::setAccelY(const QVariant val) {
    m_accelY = val;
}

void BleModelDeviceItem::setAccelZ(const QVariant val) {
    m_accelZ = val;
}

QVariant BleModelDeviceItem::getDevName() const {
    return m_devName;
}

QVariant BleModelDeviceItem::getDevAddr() const {
    return m_devAddr;
}

QVariant BleModelDeviceItem::getRssi() const {
    return m_rssi;
}

QVariant BleModelDeviceItem::getAccelX() const {
    return m_accelX;
}

QVariant BleModelDeviceItem::getAccelY() const {
    return m_accelY;
}

QVariant BleModelDeviceItem::getAccelZ() const {
    return m_accelZ;
}

QBluetoothDeviceInfo & BleModelDeviceItem::getDevInfo() {
    return m_dev_info;
}

DeviceInfo* BleModelDeviceItem::getDevCustomInfo() const {
    return m_custom_info;
}
