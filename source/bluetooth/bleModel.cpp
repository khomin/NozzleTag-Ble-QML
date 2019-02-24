#include "bleModel.h"
#include "bleModelItem.h"

BleModel::BleModel(QObject *parent) :
    QObject(parent),
    m_tree(QList<BleModelItem*>()) {


    m_tree.append(new BleModelItem("Wolf", "Medium"));
    emit treeChanged();
//    m_tree.addAnimal(Animal("Polar bear", "Large"));
//    m_tree.addAnimal(Animal("Quoll", "Small"));

}

//BleModelItem * BleModel::createTreeItem(QString nameInterface) {
//    auto res = new BleModelItem(nameInterface, true);
//    return res;
//}

//BleModelItem * BleModel::createTreeSubItem(QString nameDevice) {
//    auto res = new BleModelItem(nameDevice, false);
//    connect(res, SIGNAL(currentIndexIsChanged(bool, BleModelItem*)), this, SLOT(currentIndexIsChanged(bool, BleModelItem*)));
//    return res;
//}

//void BleModel::addConnection(QString connectionName) {
//    if(!m_tree.empty()) {
//        for(auto it:m_tree) {
//            it->setIsCurrent(false);
//        }
//    }
//    BleModelItem * titem = createTreeItem(connectionName);
//    m_tree.append(std::move(titem));
//    connect(titem, SIGNAL(currentIndexIsChanged(bool, BleModelItem*)), this, SLOT(currentIndexIsChanged(bool, BleModelItem*)));
//    treeChanged();
//    emit currentIndexIsChanged(false, titem);
//    setIoIndex(m_tree.size()-1);
//}

//void BleModel::removeConnection(int indexConnection) {
//    disconnectaFullTree();
//    m_tree.removeAt(indexConnection);
//    if(!m_tree.empty()) {
//        m_tree.first()->setIsCurrent(true);
//        setIoIndex(m_tree.size()-1);
//    } else {
//        setIoIndex(0);
//    }
//    connectFullTree();
//    treeChanged();
//}

//void BleModel::removeAll() {
//    disconnectaFullTree();
//    m_tree.clear();
//    setIoIndex(0);
//    setDevIndex(0);
//    connectFullTree();
//    treeChanged();
//}

//void BleModel::addDeviceToConnection(QString connName, QString devName) {
//    for(auto it: m_tree) {
//        if(it->content() == connName) {
//            BleModelItem * tDevItem = createTreeSubItem(devName);
//            tDevItem->setIsCurrent(true);
//            it->addChildItem(std::move(tDevItem));
//            it->setIsParent(true);
//            it->setIsOpen(true);
//            setDevIndex(it->childItems().size()-1);
//            treeChanged();
//        }
//    }
//}

//bool BleModel::changeDeviceName(QString nameConnection, QString devName, QString devNewName) {
//    bool res = false;
//    for(auto it: m_tree) {
//        if(it->content() == nameConnection) {
//            for(auto devs:it->childItems()) {
//                if(devs->content() == devName) {
//                    devs->setContent(devNewName);
//                    res = true;
//                }
//            }
//            treeChanged();
//        }
//    }
//    return res;
//}

//bool BleModel::changeDeviceHeader(QString nameConnection, QString devName, QString devNewHeader) {
//    bool res = false;
//    for(auto it: m_tree) {
//        if(it->content() == nameConnection) {
//            for(auto devs:it->childItems()) {
//                if(devs->content() == devName) {
//                    devs->setHeader(devNewHeader);
//                    res = true;
//                }
//            }
//            treeChanged();
//        }
//    }
//    return res;
//}

//void BleModel::removeDeviceToConnection(int indexConnection, int indexDevice) {
//    disconnectaFullTree();
//    m_tree.at(indexConnection)->removeChildByIndexChild(indexDevice);
//    connectFullTree();
//    if(!m_tree.at(indexConnection)->childItems().isEmpty()) {
//        setDevIndex(m_tree.at(indexConnection)->childItems().size()-1);
//    } else {
//        for(auto it:m_tree) {
//            it->setIsCurrent(false);
//        }
//        m_tree[indexConnection]->setIsCurrent(true);
//        setDevIndex(0);
//    }
//    treeChanged();
//}

const QList<BleModelItem *> &BleModel::tree() const{
    return m_tree;
}

const QList<QObject *> BleModel::treeAsQObjects() const{
    QList<QObject *> res;
    res.reserve(m_tree.count());
    for(auto i : m_tree)
        res.append(i);
    return res;
}

//void BleModel::disconnectaFullTree() {
//    for(auto it: m_tree) {
//        disconnect(it, SIGNAL(currentIndexIsChanged(bool, BleModelItem*)), this, SLOT(currentIndexIsChanged(bool, BleModelItem*)));
//        for(auto it2:it->childItems()) {
//            disconnect(it2, SIGNAL(currentIndexIsChanged(bool, BleModelItem*)), this, SLOT(currentIndexIsChanged(bool, BleModelItem*)));
//        }
//    }
//}

//void BleModel::connectFullTree() {
//    for(auto it: m_tree) {
//        connect(it, SIGNAL(currentIndexIsChanged(bool, BleModelItem*)), this, SLOT(currentIndexIsChanged(bool, BleModelItem*)));
//        for(auto it2:it->childItems()) {
//            connect(it2, SIGNAL(currentIndexIsChanged(bool, BleModelItem*)), this, SLOT(currentIndexIsChanged(bool, BleModelItem*)));
//        }
//    }
//}

//int BleModel::getDevIndex() {
//    return curIndex.devIndex;
//}

//int BleModel::getIoIndex() {
//    return curIndex.ioIndex;
//}

//void BleModel::setDevIndex(int index) {
//    curIndex.devIndex = index;
//}

//void BleModel::setIoIndex(int index) {
//    curIndex.ioIndex = index;
//}

//void BleModel::setIoStatus(int ioIndex, int status) {
//    BleModelItem *p_io = nullptr;
//    if(m_tree.size() >= ioIndex+1) {
//        p_io = m_tree.at(ioIndex);
//        if(p_io != nullptr) {
//            p_io->setConnected((bool)status);
//        }
//    }
//}

//void BleModel::setDevStatus(int devIndex, int status) {
//    BleModelItem *p_dev = nullptr;
//    p_dev = m_tree.at(curIndex.ioIndex);
//    if(p_dev != nullptr) {
//        if(!p_dev->childItems().isEmpty()) {
//            p_dev->childItems().at(devIndex)->setConnected((bool)status);
//        }
//    }
//}

//void BleModel::currentIndexIsChanged(bool, BleModelItem *pSender) {
//    disconnectaFullTree();
//    if(pSender->isParent()) {
//        int index = 0;
//        for(auto it: m_tree) {
//            for(auto ch = it->childItems().begin(); ch!= it->childItems().end(); ch++) {
//                (*ch)->setIsCurrent(false);
//            }
//        }
//        for(auto it: m_tree) {
//            if(it == pSender) {
//                it->setIsCurrent(true);
//                setIoIndex(index);
//                setDevIndex(0);
//                emit currentIndexIsChangedInteface(index);
//            } else {
//                it->setIsCurrent(false);
//            }
//            index++;
//        }
//    } else {
//        int indexParent = 0;
//        for(auto it: m_tree) {
//            it->setIsCurrent(false);
//            int indexChild = 0;
//            // находим своего родителя и делаем его активным
//            for(auto it2: it->childItems()) {
//                if(it2 == pSender) {
//                    it2->setIsCurrent(true);
//                    setDevIndex(indexChild);
//                    setIoIndex(indexParent);
//                    emit currentIndexIsChangedDevice(indexParent, indexChild);
//                } else {
//                    it2->setIsCurrent(false);
//                }
//                indexChild++;
//            }
//            indexParent++;
//        }
//    }
//    connectFullTree();
//}
