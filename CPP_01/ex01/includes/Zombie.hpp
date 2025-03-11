#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	private:	
		std::string	_name;
	
	public:
		Zombie();
		~Zombie();
		
		void		setName(std::string name);
		std::string	getName(void);

		void	announce(void);

};

Zombie*	zombieHorde(int N, std::string name);

#endif
