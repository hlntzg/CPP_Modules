#include "Zombie.hpp"

int	main(void) {
	std::cout	<< std::endl
				<< "   WELCOME TO ZOMBIE MOAR BRAINZ!  " << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;

	int			numZombies = 15;
	std::string	nameZombies = "Zuuumbie";
	
	Zombie*	horde = zombieHorde(numZombies, nameZombies);

	if (horde != nullptr) {
		for (int i = 0; i < numZombies; i++) {
			horde[i].announce();
        }
        delete[] horde;
	}
    else {
		std::cout << "Failed to create zombie horde." << std::endl;
    }
    return (0);
}
