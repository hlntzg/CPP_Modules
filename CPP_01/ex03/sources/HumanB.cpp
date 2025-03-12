#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(nullptr) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& newWeapon) {
	_weapon = &newWeapon;
}

void	HumanB::attack(void) const {
	if (_weapon) {
		std::cout	<< _name
					<< " attacks with their "
					<< _weapon->getType() << std::endl;
	}
	else {
		std::cout	<< _name << " has no weapon to attack with!" << std::endl;
	}
}
