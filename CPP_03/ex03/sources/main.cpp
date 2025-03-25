/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:31:11 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/25 16:52:04 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

int	main(void) {

	std::cout	<< "----------------------------------------" << std::endl;
	std::cout	<< "            Constructor Tests           " << std::endl;;
	std::cout	<< "----------------------------------------" << std::endl;
	FlagTrap	a("A");
	FlagTrap	b("B");
	FlagTrap	c("C");

	std::cout	<< "----------------------------------------" << std::endl;
	std::cout	<< "  Copy Constructor & Assignment Tests   " << std::endl;
	std::cout	<< "----------------------------------------" << std::endl;
	FlagTrap	d(c);	// Copy Constructor
	d = b;			    // Copy Assignment Operator

	std::cout	<< "----------------------------------------" << std::endl;
	std::cout	<< "                 Attack Tests           "  << std::endl;
	std::cout	<< "----------------------------------------" << std::endl;
	a.attack("B");
	b.takeDamage(20);

	a.attack("B");
	b.takeDamage(20);

	a.attack("B");
	b.takeDamage(20);

	a.attack("B");
	b.takeDamage(20);

	a.attack("B");
	b.takeDamage(20);

	std::cout	<< "----------------------------------------" << std::endl;
	std::cout	<< "                Edge Cases              " <<  std::endl;
	std::cout	<< "----------------------------------------" << std::endl;
	b.attack("A");		// b cannot attack, no hit points left
	b.beRepaired(10);	// Should fail due to zero hit points

	std::cout	<< "----------------------------------------" << std::endl;
	std::cout	<< "             Special Ability            " << std::endl;
	std::cout	<< "----------------------------------------" << std::endl;
	a.highFivesGuys();	// Test FlagTrap's unique highFive mode

	std::cout	<< "----------------------------------------" << std::endl;

	return (0);
}
