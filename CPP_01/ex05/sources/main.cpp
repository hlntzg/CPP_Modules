/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:29:14 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/19 16:29:16 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define SWAP "\033[7m";
#define RESET "\033[0m";

int	main(void)
{
	std::cout	<< std::endl
				<< "WELCOME TO HARL 2.0 - Harl complains" << std::endl
				<< "------------------------------------" << std::endl
				<< std::endl;
	
	Harl	harl;
	
	std::cout	<< SWAP << "  TESTING HARL 2.0 FOR DEBUG LEVEL  " << RESET << std::endl
				<< "------------------------------------" << std::endl;
	harl.complain("DEBUG");
	std::cout	<< std::endl;
	
	std::cout	<< SWAP << "  TESTING HARL 2.0 FOR INFO LEVEL   " << RESET << std::endl
				<< "------------------------------------" << std::endl;
	harl.complain("INFO");
	std::cout	<< std::endl;
	
	std::cout	<< SWAP << " TESTING HARL 2.0 FOR WARNING LEVEL " << RESET << std::endl
				<< "------------------------------------" << std::endl;
	harl.complain("WARNING");
	std::cout	<< std::endl;
	
	std::cout	<< SWAP << "  TESTING HARL 2.0 FOR ERROR LEVEL  " << RESET << std::endl
				<< "------------------------------------" << std::endl;
	harl.complain("ERROR");
	std::cout	<< std::endl;
	
	return (0);
}
