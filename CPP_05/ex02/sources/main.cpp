/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:28:33 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/03 16:22:56 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int	main(void) {

    std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Default constructor ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try	{
		//AForm		f0; //'AForm' is an abstract class

		Bureaucrat	b0;
		std::cout << b0 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;

		ShrubberyCreationForm	s0;
		std::cout << s0 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;

		RobotomyRequestForm	r0;
		std::cout << r0 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		PresidentialPardonForm	p0;
		std::cout << p0 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}

    std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Copy & Copy Assignment Operator ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {

	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
    
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Valid Bureaucrat ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	std::cout	<< " - ShrubberyCreationForm" << std::endl;	
	try {

	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}

	std::cout	<< " - RobotomyRequestForm" << std::endl;	
	try {

	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}

	std::cout	<< " - PresidentialPardonForm" << std::endl;	
	try {

	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}

	return (0);
}
