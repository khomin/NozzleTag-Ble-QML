#ifndef ANIMALMODEL_H
#define ANIMALMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "animal.h"
#include <QHash>

class AnimalModel : public QAbstractListModel
{
    Q_OBJECT
public:
    AnimalModel(QObject *parent = nullptr);

    enum AnimalRoles {
        TypeRole = Qt::UserRole + 1,
        SizeRole
    };

    void addAnimal(const Animal * animal);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Animal*> m_animals;
};

#endif // ANIMALMODEL_H
