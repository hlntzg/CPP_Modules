/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:31:11 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/26 15:28:16 by hutzig           ###   ########.fr       */
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
	std::cout	<< "----------------------------------------" << std::endl;
	d = b;			    // Copy Assignment Operator


	std::cout	<< "----------------------------------------" << std::endl;
	d.whoAmI();
	d.howManyPoints(); 
	b.whoAmI();
	b.howManyPoints(); 

	
	std::cout	<< "----------------------------------------" << std::endl;
	std::cout	<< "                 Attack Tests           "  << std::endl;
	std::cout	<< "----------------------------------------" << std::endl;
	a.whoAmI();
	std::cout	<< "----------------------------------------" << std::endl;
	a.howManyPoints(); 
	std::cout	<< "----------------------------------------" << std::endl;
	a.attack("B");
	b.takeDamage(30);
	
	a.attack("B");
	b.takeDamage(30);

	a.attack("B");
	b.takeDamage(30);

	a.attack("B");
	b.takeDamage(30);

	a.attack("B");
	b.takeDamage(30);

	std::cout	<< "----------------------------------------" << std::endl;
	b.howManyPoints();
	std::cout	<< "----------------------------------------" << std::endl;
	
	b.attack("A");	
	b.beRepaired(10);

	std::cout	<< "----------------------------------------" << std::endl;
	a.whoAmI();
	std::cout	<< "----------------------------------------" << std::endl;
	a.howManyPoints();
	std::cout	<< "----------------------------------------" << std::endl;
	x.whoAmI();
	std::cout	<< "----------------------------------------" << std::endl;
	x.howManyPoints();
	std::cout	<< "----------------------------------------" << std::endl;

	return (0);
}
