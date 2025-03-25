/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:35:53 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/25 12:21:54 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	
	std::cout	<< "-----------------------------------------" << std::endl;
	
	ClapTrap	a;
	ClapTrap	b("B");
	ClapTrap	c(b);

	a.attack("someone");
	a.takeDamage(5);
	a.beRepaired(3);
	a.takeDamage(9);
	a.beRepaired(1);
}
