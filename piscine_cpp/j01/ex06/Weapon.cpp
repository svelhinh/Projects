#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
    return;
}

Weapon::~Weapon(void)
{
    return;
}

std::string Weapon::getType(void) const
{
    std::string const &ref = this->_type;
    return ref;
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}
