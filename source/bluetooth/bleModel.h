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
        RoleAddr
    };

    void addBle(const BleModelItem * bleItem);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<BleModelItem*> bleDevices;

//    void addConnection(QString name);
//    void removeConnection(int index);
//    void removeAll();

//    void addDeviceToConnection(QString connName, QString devName);
//    void removeDeviceToConnection(int indexConnection, int indexDevice);
//    bool changeDeviceName(QString nameConnection, QString devName, QString devNewName);
//    bool changeDeviceHeader(QString nameConnection, QString devName, QString devNewHeader);

//    int getDevIndex();
//    int getIoIndex();
//    void setDevIndex(int);
//    void setIoIndex(int);

//    void setDevStatus(int devIndex, int status);

//    void setIoStatus(int ioIndex, int status);

//signals:
//    void treeChanged();
//    void currentIndexIsChangedDevice(int interfaceIndex, int deviceIndex);
//    void currentIndexIsChangedInteface(int index);


//private slots:

//    BleModelItem *createTreeItem(QString nameInterface);
//    BleModelItem *createTreeSubItem(QString nameDevice);

//    void currentIndexIsChanged(bool isParent, BleModelItem *pSender);

//    void disconnectaFullTree();
//    void connectFullTree();

//private:
//    QList<BleModelItem*> m_tree;

//    typedef struct {
//        int ioIndex;
//        int devIndex;
//    }sIndex;

//    sIndex curIndex = {0, 0};
};

#endif // BleModel_H
