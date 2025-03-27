/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:31:11 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 11:53:51 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void) {

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Creating ScavTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	ScavTrap	scav0;
	ScavTrap	scav1("ScavOne");
	ScavTrap	scav2("ScavTwo");
	ScavTrap	scav3 = scav1;
	ScavTrap	scav4(scav1);

	scav4 = scav0;


	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Attack Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	scav0.attack("ScavOne");            
	scav1.attack("ScavTwo");
	scav2.attack("ScavThree");
	scav3.attack("ScavZero");

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Take Damage Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	scav0.takeDamage(10);
	scav1.takeDamage(30);
	scav2.takeDamage(50);
	scav1.takeDamage(80); // Should reduce hit points to 0

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Be Repaired Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	scav0.beRepaired(10);
	scav1.beRepaired(20); // Should not be possible, as ScavOne has 0 hit points
	scav2.beRepaired(15);
	scav3.beRepaired(25);

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Guard Gate Mode ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	scav0.guardGate();
	scav1.guardGate();
	scav2.guardGate();
	scav3.guardGate();
	scav4.guardGate();

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Draining Energy ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	for (int i = 0; i < 50; i++) {
		scav3.attack("SOMEONE");
	}
	scav3.attack("SOMEONE"); // Should not be possible, energy is 0
	scav3.beRepaired(5); // Should not be possible, energy is 0

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Destroying ScavTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	
	return (0);
}
