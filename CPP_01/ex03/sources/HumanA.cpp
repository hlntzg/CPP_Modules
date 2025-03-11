#include "HumanA.hpp"

HumanA::HumanA(std::string firstName, Weapon& firstWeapon) : _name(firstName), _weapon(firstWeapon) {
	return ;
}

HumanA::~HumanA {
	return ;
}

void	HumanA::attack(void) {
	std::cout	<< _name
				<< " attacks with their "
				<< _weapon.getType() << std::endl;
	return ;
}

