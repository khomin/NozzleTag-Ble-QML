#ifndef BleModelItem_H
#define BleModelItem_H

#include <QObject>

class BleModelItem : public QObject
{
    Q_OBJECT
public:
    BleModelItem(const QString devName, const QString devAddr);
    BleModelItem(const BleModelItem & item) {
        this->m_devName = item.m_devName;
        this->m_devAddr = item.m_devAddr;
    }
    QString getDevName() const;
    QString getDevAddr() const;

private:
    QString m_devName;
    QString m_devAddr;
};

#endif // BleModelItem_H
