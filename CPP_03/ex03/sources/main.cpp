/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:31:11 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/26 14:09:31 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {

	std::cout	<< "----------------------------------------" << std::endl;
	std::cout	<< "            Constructor Tests           " << std::endl;;
	std::cout	<< "----------------------------------------" << std::endl;
	DiamondTrap	x;
	DiamondTrap	a("A");
	DiamondTrap	b("B");
	DiamondTrap	c("C");

	std::cout	<< "----------------------------------------" << std::endl;
	std::cout	<< "  Copy Constructor & Assignment Tests   " << std::endl;
	std::cout	<< "----------------------------------------" << std::endl;
	DiamondTrap	d(c);	// Copy Constructor
	d = b;			    // Copy Assignment Operator

	std::cout	<< "----------------------------------------" << std::endl;
	std::cout	<< "                 Attack Tests           "  << std::endl;
	std::cout	<< "----------------------------------------" << std::endl;
	a.whoAmI();
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
	a.whoAmI();
	a.howManyPoints();
	x.whoAmI();
	x.howManyPoints();
	std::cout	<< "----------------------------------------" << std::endl;

	return (0);
}
