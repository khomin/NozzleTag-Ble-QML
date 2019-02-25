#ifndef BleModelItem_H
#define BleModelItem_H

#include <QObject>

class BleModelItem : public QObject
{
    Q_OBJECT
public:
    BleModelItem(const QString devName, const QString devAddr, const int rssi);
    BleModelItem(const BleModelItem & item) {
        this->m_devName = item.m_devName;
        this->m_devAddr = item.m_devAddr;
        this->m_rssi = item.m_rssi;
    }
    QString getDevName() const;
    QString getDevAddr() const;
    int getRssi() const;

private:
    QString m_devName;
    QString m_devAddr;
    int m_rssi;
    QList<QObject*> m_services;
};

#endif // BleModelItem_H
