/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:31:11 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 12:02:44 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {


	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Default constructor ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    DiamondTrap	dt1;
    dt1.whoAmI();
    dt1.howManyPoints();
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Parameterized constructor ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    DiamondTrap	dt2("MyDiamond");
    dt2.whoAmI();
    dt2.howManyPoints();
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Copy constructor ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    DiamondTrap dt3(dt2);
    dt3.whoAmI();
    dt3.howManyPoints();

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Attack Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    dt1.howManyPoints();
	dt1.attack("Graphite");
    dt1.howManyPoints();
	std::cout	<< "-----------------------------------------" << std::endl;
    dt2.howManyPoints();
    dt2.attack("Graphene");
    dt2.howManyPoints();
	std::cout	<< "-----------------------------------------" << std::endl;
    dt3.howManyPoints();
	dt3.attack("Buckminsterfullerene");
    dt3.howManyPoints();
	std::cout	<< "-----------------------------------------" << std::endl;
    dt1.whoAmI();
    dt1.howManyPoints();
	for (int i = 0; i < 100; i++) {
		dt1.attack("Lonsdaleite");
	}
	dt1.attack("Fullerene"); // Should not be possible, energy is 0
	dt1.attack("Amorphous carbon"); // Should not be possible, energy is 0
	dt1.beRepaired(5); // Should not be possible, energy is 0
    dt1.whoAmI();
    dt1.howManyPoints();

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Take Damage & Repair ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    dt2.howManyPoints();
    dt2.takeDamage(50);
    dt2.howManyPoints();
    dt2.beRepaired(30);
    dt2.howManyPoints();
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Hive Five & Guard Gate Modes ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    dt1.highFivesGuys();
    dt1.guardGate();
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Copy Assignment Operator ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    dt2.whoAmI();
    dt2.howManyPoints();
    dt3 = dt2;
    dt3.whoAmI();
    dt3.howManyPoints();
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Destroying DiamondTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;

    return (0);
}
