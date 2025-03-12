#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon&		_weapon; // reference to Weapon (cannot be null)
	public:
		HumanA(const std::string& name, Weapon& aWeapon);
		~HumanA();
		
		void	attack(void) const;
};

#endif
