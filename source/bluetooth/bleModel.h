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

    void addBle(const BleModelItem * bleItem);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<BleModelItem*> bleDevices;
};

#endif // BleModel_H
