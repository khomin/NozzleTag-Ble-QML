#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>

class Animal : public QObject
{
    Q_OBJECT
public:
    Animal(const QString type, const QString size);
    Animal(const Animal & animal) {
        this->m_size = animal.m_size;
        this->m_type = animal.m_type;
    }
    QString type() const;
    QString size() const;

private:
    QString m_type;
    QString m_size;
};

#endif // ANIMAL_H
