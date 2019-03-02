#ifndef BLEMODEL_SERVICE_H
#define BLEMODEL_SERVICE_H

#include <QObject>
#include "source/bluetooth/service/bleModelServicetem.h"
#include <QAbstractListModel>

class BleModelService: public QAbstractListModel
{
    Q_OBJECT
public:
    BleModelService(QObject *parent = nullptr);

    enum BleRoles {
        RoleName = Qt::UserRole + 1,
        RoleUuid,
        RoleValueHex,
        RoleValueAsci
    };

    void appendBleService(const BleModelServiceItem * bleItem);
    int getCountDevices();
    QList<BleModelServiceItem*>& getBleService();
    void clearAll();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool removeRows(int index, int rows, const QModelIndex & parent) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<BleModelServiceItem*> m_ble_services;
    QHash<int, QByteArray> m_role_mame_mapping;
};

#endif // BLEMODEL_SERVICE_H
