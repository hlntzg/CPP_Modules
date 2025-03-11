#include "HumanB.hpp"

HumanB::HumanB {
	return ;
}

HumanB::~HumanB {
	return ;
}

void	HumanB::attack(void) {
	std::cout	<< _name
				<< " attacks with their "
				<< _weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(const Weapon& newWeapon) {
	_weapon = &newWeapon;
}
