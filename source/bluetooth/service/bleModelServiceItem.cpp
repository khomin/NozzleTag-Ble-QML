#include "bleModelServicetem.h"

BleModelServiceItem::BleModelServiceItem(QString name, QString uuid, QString valueHex, QString valueAsci) :
    m_name(name),
    m_uuid(uuid),
    m_value_hex(valueHex),
    m_value_asci(valueAsci) {
}

QString BleModelServiceItem::getName() const {
    return m_name;
}

QString BleModelServiceItem::getUuid() const {
    return m_uuid;
}

QString BleModelServiceItem::getValueHex() const {
    return m_value_hex;
}

QString BleModelServiceItem::getValueAsci() const {
    return m_value_asci;
}

QString BleModelServiceItem::setName(QString name) {
    m_name = name;
}

QString BleModelServiceItem::setUuid(QString uuid) {
    m_uuid = uuid;
}

QString BleModelServiceItem::setValueHex(QString valueHex) {
    m_value_hex = valueHex;
}

QString BleModelServiceItem::setValueAsci(QString valueAsci) {
    m_value_asci = valueAsci;
}
