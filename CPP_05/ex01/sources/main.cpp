/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:09:07 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/04 11:02:11 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void	testDefaultBureaucrat();
static void	testDefaultForm();
static void	testValidBureaucratGrade();
static void	testInvalidFormGrade();
static void	testInvalidBureaucratGradeToSign();

int	main(void) {

	testDefaultBureaucrat();
	testDefaultForm();
	testValidBureaucratGrade();
	testInvalidFormGrade();
	testInvalidBureaucratGradeToSign();

	std::cout << "-----------------------------------------" << std::endl
              << "[ All tests done! ]" << std::endl
              << "-----------------------------------------" << std::endl;

    return (0);
}

static void	testDefaultBureaucrat() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Bureaucrat default constructor ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat b0;
		std::cout << b0 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		Bureaucrat b("b", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
}

static void	testDefaultForm() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Form default constructor & copy ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Form		f0;
		std::cout << f0 << std::endl;
		Form		f1(f0);
		std::cout << f1 << std::endl;
		Form		fCopy("Form", 42, 42);
		std::cout << fCopy << std::endl;
		f0 = fCopy;
		std::cout << f0 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
}

static void	testValidBureaucratGrade() {
    std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Valid Bureaucrat grade to sign ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    try {
		Form		f1("A", 50, 100);
        std::cout << f1 << std::endl;
        Bureaucrat	b1("b1", 45);
        std::cout << b1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
    }
	catch (std::exception &e) {
        std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
    }
    try {
        Form		f2("B", 42, 42);
        std::cout << f2 << std::endl;
        Bureaucrat	b2("b2", 42);
		std::cout << b2 << std::endl;
        b2.signForm(f2);
        std::cout << f2 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
    }
	catch (std::exception &e) {
        std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
    }
}

static void	testInvalidFormGrade() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Invalid Form grade ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Form		f3("C", 0, 10);
		std::cout << "-----------------------------------------" << std::endl;
    }
	catch (std::exception &e) {
        std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
    }
	try {
		Form		f4("D", 10, 151);
		std::cout << "-----------------------------------------" << std::endl;
    }
	catch (std::exception &e) {
        std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
    }
}

static void	testInvalidBureaucratGradeToSign() {
    std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Invalid Bureaucrat grade to sign ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    try {
        Form		f5("E", 30, 50);
        Bureaucrat	b2("b2", 40);
        std::cout << f5 << std::endl;
        b2.signForm(f5);  // Should fail due to insufficient grade
        std::cout << f5 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
    }
	catch (std::exception &e) {
        std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
    }
}
