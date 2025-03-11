#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	
	if (N <= 0) {
		std::cout << "Invalid number of zombies requested." << std::endl;
		return (nullptr);
	}
	
	Zombie*	horde = nullptr;
	
	try {
		horde = new Zombie[N];
	}
	catch (std::bad_alloc&) {
		std::cout << "Memory allocation failed." << std::endl;
		return (nullptr);
	}
	// Initialize each Zombie with the given name, adding index for uniqueness:w
	for (int i = 0; i < N; i++) {
		horde[i].setName(name + "_" + std::to_string(i + 1));
	}
	return (horde);
}
