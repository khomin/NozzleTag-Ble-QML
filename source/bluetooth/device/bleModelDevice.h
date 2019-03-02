#ifndef BLEMODEL_DEVICE_H
#define BLEMODEL_DEVICE_H

#include <QObject>
#include "source/bluetooth/device/bleModelDeviceItem.h"
#include <QAbstractListModel>

class BleModelDeviceItem;

class BleModelDevice : public QAbstractListModel
{
    Q_OBJECT
public:
    BleModelDevice(QObject *parent = nullptr);

    enum BleRoles {
        RoleName = Qt::UserRole + 1,
        RoleAddr,
        RoleRssi,
        RoleAccelX,
        RoleAccelY,
        RoleAccelZ
    };

    void appendBleDevice(const BleModelDeviceItem* bleItem);

    int getCountDevices();

    QList<BleModelDeviceItem*>& getBleDevices() const;

    void clearAll();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool removeRows(int index, int rows, const QModelIndex & parent);

    QHash<int, QByteArray> roleNames() const override;

private:
    mutable QList<BleModelDeviceItem*> bleDevices;
    QHash<int, QByteArray> roleNameMapping;
};

#endif // BLEMODEL_DEVICE_H
