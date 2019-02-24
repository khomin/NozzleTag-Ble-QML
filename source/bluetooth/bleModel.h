#ifndef BleModel_H
#define BleModel_H

#include <QObject>

class BleModelItem;

class BleModel : public QObject
{
    Q_OBJECT
public:
    explicit BleModel(QObject *parent = 0);

    Q_PROPERTY(QList<QObject*> tree READ treeAsQObjects NOTIFY treeChanged)
    const QList<BleModelItem*> &tree() const;
    const QList<QObject*> treeAsQObjects() const;

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

signals:
    void treeChanged();
//    void currentIndexIsChangedDevice(int interfaceIndex, int deviceIndex);
//    void currentIndexIsChangedInteface(int index);


private slots:

//    BleModelItem *createTreeItem(QString nameInterface);
//    BleModelItem *createTreeSubItem(QString nameDevice);

//    void currentIndexIsChanged(bool isParent, BleModelItem *pSender);

//    void disconnectaFullTree();
//    void connectFullTree();

private:
    QList<BleModelItem*> m_tree;

//    typedef struct {
//        int ioIndex;
//        int devIndex;
//    }sIndex;

//    sIndex curIndex = {0, 0};
};

#endif // BleModel_H
