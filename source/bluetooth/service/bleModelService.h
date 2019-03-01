#ifndef BLEMODEL_SERVICE_H
#define BLEMODEL_SERVICE_H

#include <QObject>
#include "source/bluetooth/bleModelItem.h"
#include <QAbstractListModel>

class BleModelService: public QAbstractListModel
{
    Q_OBJECT
public:
    BleModelService(QObject *parent = nullptr);

    enum BleRoles {
        RoleName = Qt::UserRole + 1,
        RoleAddr,
        RoleRssi
    };

    void appendBleService(const BleModelItem * bleItem);

    int getCountDevices();

    QList<BleModelItem*>& getBleDevices();

    void clearAll();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool removeRows(int index, int rows, const QModelIndex & parent) override;

    QHash<int, QByteArray> roleNames() const override;

private:
    QList<BleModelItem*> bleDevices;
    QHash<int, QByteArray> roleNameMapping;
};

#endif // BLEMODEL_SERVICE_H
