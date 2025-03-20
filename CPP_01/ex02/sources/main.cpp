/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:25:24 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/20 08:46:44 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::cout	<< std::endl
				<< "WELCOME TO THE ADDRESS MANIPULATION" << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;

	std::string		myString = "HI THIS IS BRAIN";		// string variable
	std::string*	stringPTR = &myString;				// pointer to the string
	std::string&	stringREF = myString;				// reference to the string

	std::cout	<< std::endl
				<< "     VARIABLES' MEMORY ADDRESS     " << std::endl
				<< "-----------------------------------" << std::endl
				<< "myString:\t" << &myString << std::endl
				<< "stringPTR:\t" << stringPTR << std::endl
				<< "stringREF:\t" << &stringREF << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;

	std::cout	<< std::endl
				<< "       VALUE OF THE VARIABLES      " << std::endl
				<< "-----------------------------------" << std::endl
				<< "myString:\t" << myString << std::endl
				<< "stringPTR:\t" << *stringPTR << std::endl
				<< "stringREF:\t" << stringREF << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;

	return (0);
}
