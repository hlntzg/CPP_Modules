#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& aWeapon) : _name(name), _weapon(aWeapon) {}

HumanA::~HumanA() {}

void	HumanA::attack(void) const {
	std::cout	<< _name
				<< " attacks with their "
				<< _weapon.getType() << std::endl;
}

