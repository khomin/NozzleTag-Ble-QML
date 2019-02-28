#ifndef BleModel_H
#define BleModel_H

#include <QObject>
#include "source/bluetooth/bleModelItem.h"
#include <QAbstractListModel>

class BleModelItem;

class BleModel : public QAbstractListModel
{
    Q_OBJECT
public:
    BleModel(QObject *parent = nullptr);

    enum BleRoles {
        RoleName = Qt::UserRole + 1,
        RoleAddr,
        RoleRssi
    };

    void appendBleDevice(const BleModelItem * bleItem);

    int getCountDevices();

    QList<BleModelItem*>& getBleDevices();

    void clearAll();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool removeRows(int index, int rows, const QModelIndex & parent);

    QHash<int, QByteArray> roleNames() const override;

private:
    QList<BleModelItem*> bleDevices;
    QHash<int, QByteArray> roleNameMapping;
};

#endif // BleModel_H
