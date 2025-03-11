#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
	private:
		std::string	_type;
	public:
		Weapon();
		~Weapon();
		void				setType(const std::string newType);
		const std::string&	getType(void);
};

#endif
