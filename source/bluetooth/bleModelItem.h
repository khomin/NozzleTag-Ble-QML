#ifndef BleModelItem_H
#define BleModelItem_H

#include <QObject>

class BleModelItem : public QObject
{
    Q_OBJECT
public:
    explicit BleModelItem(QString content, bool isParent, QObject *parent = 0);

    Q_PROPERTY(QString content READ content NOTIFY contentChanged)
    const QString & content() const;
    void setContent(const QString & content);

//    Q_PROPERTY(QString header READ header NOTIFY headerChanged)
//    const QString & header() const;
//    void setHeader(const QString & header);

//    Q_PROPERTY(QList<QObject*> childItems READ childItemsAsQObject NOTIFY childItemsChanged)
//    const QList<BleModelItem *> &childItems() const;
//    const QList<QObject *> childItemsAsQObject() const;
//    void addChildItem(BleModelItem * childItem);

//    Q_PROPERTY(bool isOpen READ isOpen WRITE setIsOpen NOTIFY isOpenChanged)
//    bool isOpen() const;
//    void setIsOpen(bool isOpen);

//    Q_PROPERTY(bool isConnected READ isConnected WRITE setConnected NOTIFY isConnectedChanged)
//    bool isConnected();
//    void setConnected(bool isConnected);

//    Q_PROPERTY(bool isCurrent READ isCurrent WRITE setIsCurrent NOTIFY isCurrentChanged)
//    bool isCurrent() const;
//    void setIsCurrent(bool isCurrent);

//    Q_PROPERTY(bool hasChild READ hasChild NOTIFY hasChildChanged)
//    bool hasChild() const;

//    void setIsParent(bool parent);
//    bool isParent() const;

//    void removeChildByIndexChild(int index);

signals:
    void contentChanged();
//    void headerChanged();
//    void currentIndexIsChanged(bool isParent, BleModelItem *pSender);
//    void childItemsChanged();
//    void isOpenChanged();
//    void isCurrentChanged();
    void isConnectedChanged();
//    void hasChildChanged();
public slots:
private:
    QString m_content;
    QString m_header;
//    QList<BleModelItem *> m_childItems;
//    bool m_isParent;
//    bool m_isOpen;
//    bool m_isCurrent;
//    bool m_isConnected;
};

#endif // BleModelItem_H
