#include "Zombie.hpp"

// Default Constructor
Zombie::Zombie(void) {
	//std::cout << "Default constructor created." << std::endl;
}

// Destructor
Zombie::~Zombie(void) {
	std::cout << "Zombie " << _name << " destroyed." << std::endl;
}

// Member function
void		Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void		Zombie::setName(std::string name) {
	_name = name;
}

std::string	Zombie::getName(void) {
	return (_name);
}
