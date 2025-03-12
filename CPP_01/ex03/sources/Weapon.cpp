#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {}

Weapon::~Weapon() {}

void				Weapon::setType(const std::string& newType) {
	_type = newType;
}

const std::string&	Weapon::getType(void) const {
	return (_type);
}
