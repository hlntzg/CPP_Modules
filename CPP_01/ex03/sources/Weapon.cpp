#include "Weapon.hpp"

Weapon::Weapon() {
	return ;
}

Weapon::~Weapon() {
	return ;
}

void				Weapon::setType(const std::string newType) {
	_type = newType;
}

const std::string&	Weapon::getType(void) {
	return (_type);
}
