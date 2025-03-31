/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:09:07 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/31 13:34:28 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Mommy, I want to be a bureaucrat! ]" << std::endl
				<< "-----------------------------------------" << std::endl
				<< std::endl;

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Default ]" << std::endl
				<< "-----------------------------------------" << std::endl;


	try {
		Bureaucrat	b0;
		std::cout << " - Bureaucrat name:\t" << b0.getName() <<  std::endl;
		std::cout << " - Bureaucrat grade:\t" << b0.getGrade() << std::endl;
		std::cout << b0 << std::endl;
		std::cout	<< "-----------------------------------------" << std::endl;
		Bureaucrat	bCopy("bCopy", 42);
		std::cout << " - Bureaucrat name:\t" << bCopy.getName() <<  std::endl;
		std::cout << " - Bureaucrat grade:\t" << bCopy.getGrade() << std::endl;
		std::cout << bCopy << std::endl;
		bCopy = b0;
		std::cout << bCopy << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Instantiate with invalid grade ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< " - instantiate 151: [✗]" << std::endl;	
	try {
		Bureaucrat	b1("B1", 151);
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}

	std::cout	<< " - instantiate 0: [✗]" << std::endl;	
	try {
		Bureaucrat	b2("B2", 0);
		std::cout << b2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Decrement Bureaucrat's grade ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< " - decrementGrade(): [✔]" << std::endl;	
	try {
		Bureaucrat	b3("B3", 1);
		std::cout << b3 << std::endl;
		b3.decrementGrade();
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}

	std::cout	<< " - decrementGrade(): [✗]" << std::endl;	
	try {
		Bureaucrat	b4("B4", 150);
		std::cout << b4 << std::endl;
		b4.decrementGrade();
		std::cout << b4 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Increment Bureaucrat's grade ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< " - incrementGrade(): [✔]" << std::endl;	
	try {
		Bureaucrat	b5("B5", 150);
		std::cout << b5 << std::endl;
		b5.incrementGrade();
		std::cout << b5 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}

	std::cout	<< " - incrementGrade(): [✗]" << std::endl;	
	try {
		Bureaucrat	b6("B6", 1);
		std::cout << b6 << std::endl;
		b6.incrementGrade();
		std::cout << b6 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ All tests done! ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	return (0);
}
