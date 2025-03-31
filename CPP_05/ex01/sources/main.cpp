/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:09:07 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/31 16:21:02 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {

    std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Testing Bureaucrat and Form ]" << std::endl
				<< "-----------------------------------------" << std::endl
				<< std::endl;

    std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Bureaucrat default constructor ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat b0;
		std::cout << b0 << std::endl;
	} catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
    
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Form default constructor & copy ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Form		f0;
		std::cout << f0 << std::endl;
		Form		fCopy("Form", 42, 42);
		std::cout << fCopy << std::endl;
		f0 = fCopy;
		std::cout << f0 << std::endl;

	} catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}


    std::cout << "-----------------------------------------" << std::endl
              << "[ Test: Form creation and signing ]" << std::endl
              << "-----------------------------------------" << std::endl;
    try {
		Form		f1("A", 50, 100);
        Bureaucrat	b1("b1", 45);
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
    }

    std::cout << "-----------------------------------------" << std::endl
              << "[ Test: Bureaucrat with invalid grades ]" << std::endl
              << "-----------------------------------------" << std::endl;
	std::cout	<< " - bureaucrat cannot sign duo too low grade: [✗]" << std::endl;	
    try {
        Form		f2("B", 30, 50);
        Bureaucrat	b2("b2", 40);
        std::cout << f2 << std::endl;
        b2.signForm(f2);  // Should fail due to insufficient grade
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
    }

    std::cout << "-----------------------------------------" << std::endl
              << "[ Test: Bureaucrat with valid grades ]" << std::endl
              << "-----------------------------------------" << std::endl;
    try {
        Form		f3("C", 10, 30);
        Bureaucrat	b3("b3", 1);
        std::cout << f3 << std::endl;
        b3.signForm(f3);
        std::cout << f3 << std::endl;
    } catch (std::exception &e) {
        std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
    }

    std::cout << "-----------------------------------------" << std::endl
              << "[ Test: Bureaucrat with too low grade can't sign ]" << std::endl
              << "-----------------------------------------" << std::endl;
    try {
        Form		f4("D", 1, 100);
        Bureaucrat	b4("b4", 150);  // Too low grade to sign
        std::cout << f4 << std::endl;
        b4.signForm(f4);  // Should fail
        std::cout << f4 << std::endl;
    } catch (std::exception &e) {
        std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
    }

    std::cout << "-----------------------------------------" << std::endl
              << "[ All tests done! ]" << std::endl
              << "-----------------------------------------" << std::endl;

    return 0;
}
