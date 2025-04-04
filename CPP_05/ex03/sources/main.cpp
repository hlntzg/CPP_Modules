/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:28:33 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/04 15:23:53 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ShrubberyCreationForm.hpp"
//#include "RobotomyRequestForm.hpp"
//#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void	testDefault();
static void	testShrubberyForm();
static void	testRobotomyForm();
static void	testPresidentialForm();
static void	testRandomForm();
static void	testInvalidForm();
static void	testValidFormNullTarget();

int	main(void) {

	testDefault();
	testShrubberyForm();
	testRobotomyForm();
	testPresidentialForm();
	testRandomForm();
	testInvalidForm();
	testValidFormNullTarget();

	std::cout << "-----------------------------------------" << std::endl
              << "[ All tests done! ]" << std::endl
              << "-----------------------------------------" << std::endl;

	return (0);
}

static void	testDefault() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Default constructor ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try	{

		/**
		 * AForm		f0; -> Compiler Restriction!
		 * 'AForm' is an abstract class and cannot be instantiated directly,
		 * since it intended to be extended by subclasses that provide concrete 
		 * implementations for their abstract methods.
		 */

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

		Intern	i0;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
		return ;
	}
}

static void	testShrubberyForm() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Shrubbery Form ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Intern	i1;
		AForm*	form1;
		form1 = i1.makeForm("shrubbery", "target1");
		std::cout << *form1 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		delete form1;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
		return ;
	}
}

static void	testRobotomyForm() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Robotomy Form ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Intern	i2;
		AForm*	form2;
		form2 = i2.makeForm("robotomy", "target2");
		std::cout << *form2 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		delete form2;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
		return ;
	}
}

static void	testPresidentialForm() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Presidential Form ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Intern	i3;
		AForm*	form3;
		form3 = i3.makeForm("presidential", "target3");
		std::cout << *form3 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		delete form3;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
		return ;
	}
}

static void	testRandomForm() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Random Form ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Intern	i4;
		AForm*	form4;
		form4 = i4.makeForm("random", "target4");
		std::cout << *form4 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		delete form4;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
		return ;
	}
}

static void	testInvalidForm() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Invalid Form ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Intern	i5;
		AForm*	form5;
		form5 = i5.makeForm("", "target5");
		std::cout << *form5 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		delete form5;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
		return ;
	}
}

static void	testValidFormNullTarget() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Valid Form, null Target ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Intern	i6;
		AForm*	form6;
		form6 = i6.makeForm("presidential", "");
		std::cout << *form6 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		delete form6;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
		return ;
	}
}
