#include "bleModelItem.h"

BleModelItem::BleModelItem(QString content, bool isParent, QObject *parent) :
    QObject(parent),
    m_content(content) {
    setContent(content);
}

const QString &BleModelItem::content() const{
    return m_content;
}

void BleModelItem::setContent(const QString &content) {
    if(content != m_content){
        m_content = content;
        emit contentChanged();
    }
}

//void BleModelItem::setHeader(const QString &header) {
//    if(header != m_header){
//        m_header = header;
//        emit headerChanged();
//    }
//}

//const QString &BleModelItem::header() const{
//    return m_header;
//}

//const QList<BleModelItem *> &BleModelItem::childItems() const{
//    return m_childItems;
//}

//const QList<QObject *> BleModelItem::childItemsAsQObject() const{
//    QList<QObject *> res;
//    res.reserve(m_childItems.count());
//    for(auto i : m_childItems)
//        res.append(i);
//    return res;
//}

//void BleModelItem::addChildItem(BleModelItem *childItem){
//    m_childItems.append(childItem);
//    emit childItemsChanged();
//    if(m_childItems.count() == 1)
//        emit hasChildChanged();
//}

//void BleModelItem::removeChildByIndexChild(int index) {
//    m_childItems.removeAt(index);
//    if(!m_childItems.empty()) {
//        m_childItems.first()->setIsCurrent(true);
//    }
//    emit contentChanged();
//    emit childItemsChanged();
//    emit hasChildChanged();
//}

//bool BleModelItem::isOpen() const{
//    return m_isOpen;
//}

//void BleModelItem::setIsOpen(bool isOpen){
//    if(isOpen != m_isOpen){
//        m_isOpen = isOpen;
//        emit isOpenChanged();
//    }
//}

//bool BleModelItem::isCurrent() const {
//    return m_isCurrent;
//}

//bool BleModelItem::isParent() const {
//    return m_isParent;
//}

//void BleModelItem::setIsParent(bool parent) {
//    m_isParent = parent;
//}

//void BleModelItem::setIsCurrent(bool isCurrent) {
//    m_isCurrent = isCurrent;
//    emit currentIndexIsChanged(m_isParent, this);
//    emit isCurrentChanged();
//}

////bool BleModelItem::hasChild() const{
////    return !m_childItems.isEmpty();
////}

//bool BleModelItem::isConnected() {
//    return m_isConnected;
//}

//void BleModelItem::setConnected(bool isConnected) {
//    m_isConnected = isConnected;
//    emit isConnectedChanged();
//}
