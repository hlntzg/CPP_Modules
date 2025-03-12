#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon; // pointer to Weapon (can be null)
	public:
		HumanB(const std::string& name);
		~HumanB();
		
		void	attack(void) const;
		void	setWeapon(Weapon& newWeapon);
};

#endif
