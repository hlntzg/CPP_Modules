#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB();
		~HumanB();
		
		void	attack(void);
		void	setWeapon(const Weapon& newWeapon);
};

#endif
