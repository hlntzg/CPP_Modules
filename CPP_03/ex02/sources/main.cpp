/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:31:11 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 11:17:36 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void) {

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Creating FragTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	FragTrap	frag0;
	FragTrap	frag1("FragOne");
	FragTrap	frag2("FragTwo");
	FragTrap	frag3 = frag1;
	FragTrap	frag4(frag1);

	frag4 = frag0;

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Attack Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	frag0.attack("FragOne");
	frag1.attack("FragTwo");
	frag2.attack("FragThree");
	frag3.attack("FragZero");

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Take Damage Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	frag0.takeDamage(10);
	frag1.takeDamage(30);
	frag2.takeDamage(50);
	frag1.takeDamage(80); // Should reduce hit points to 0

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Be Repaired Function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	frag0.beRepaired(10);
	frag1.beRepaired(20); // Should not be possible, as FragOne has 0 hit points
	frag2.beRepaired(15);
	frag3.beRepaired(25);

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing High Five Mode ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	frag0.highFivesGuys();
	frag1.highFivesGuys();
	frag2.highFivesGuys();
	frag3.highFivesGuys();
	frag4.highFivesGuys();

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Draining Energy ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	for (int i = 0; i < 100; i++) {
		frag3.attack("SOMEONE");
	}
	frag3.attack("SOMEONE"); // Should not be possible, energy is 0
	frag3.beRepaired(5); // Should not be possible, energy is 0

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Destroying FragTraps ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	return (0);
}
