#ifndef ANIMALMODEL_H
#define ANIMALMODEL_H

#include <QObject>

class AnimalModel : public QObject
{
    Q_OBJECT
public:
    explicit AnimalModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ANIMALMODEL_H