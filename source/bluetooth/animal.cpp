#include "animal.h"

Animal::Animal(const QString type, const QString size)  {
    this->m_type = type;
    this->m_size = size;
}

QString Animal::type() const {
    return m_type;
}

QString Animal::size() const {
    return m_size;
}
