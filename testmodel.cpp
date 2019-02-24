#include "testmodel.h"

TestModel::TestModel(QString devName, QString devAddr,
                     QObject *parent) : QObject(parent) {
    m_devName = devName;
    m_devAddr = devAddr;
    m_isActive = false;
}

QString TestModel::getDevName() {
    return m_devName;
}

void TestModel::setDevName(QString devName) {
    m_devName = devName;
    emit devNameChanged();
}

QString TestModel::getDevAddr() {
    return m_devAddr;
}

void TestModel::setDevAddr(QString devAddr) {
    m_devName = devAddr;
    emit devAddrChanged();
}

bool TestModel::getIsActive() {
    return m_isActive;
}

void TestModel::setActive(bool active) {
    m_isActive = active;
    emit devActiveChanged();
}
