/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:24:28 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/20 09:56:13 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	std::cout	<< std::endl
				<< "WELCOME TO ZOMBIE BRAIIIIIIINNNZZZZ" << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;
	std::cout	<< "ZOMBIE TESTING FOR STACK ALLOCATION" << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;
	randomChump("MyStackZombie");
	std::cout	<< "[✔] Zombie stack allocation test finished" << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;
	std::cout	<< "ZOMBIE TESTING FOR HEAP  ALLOCATION" << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;
    Zombie* myZombie = newZombie("MyHeapZombie");
    if (myZombie != nullptr) {
		myZombie->announce();
		delete myZombie;
		std::cout	<< "[✔] Zombie heap allocation test finished" << std::endl
					<< "-----------------------------------" << std::endl
					<< std::endl;
	}
	else {
		std::cout << "Failed to create heap allocation zombie." << std::endl;
	}
	return (0);
}
