/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:28:33 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/04 10:19:18 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

static void	testDefault();
static void	testCopyConstructorCopyOperator();
static void	testValidGrade();
static void	testInvalidGradeToSign();
static void	testInvalidGradeToExecute();

int	main(void) {

/**
 * AForm		f0; -> Compiler Restriction!
 * 'AForm' is an abstract class and cannot be instantiated directly,
 * since it intended to be extended by subclasses that provide concrete 
 * implementations for their abstract methods.
 */

	testDefault();
	testCopyConstructorCopyOperator();
	testValidGrade();
	testInvalidGradeToSign();
	testInvalidGradeToExecute();

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
		return ;
	}
}

static void	testCopyConstructorCopyOperator() {
    std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Copy & Copy Assignment Operator ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< " - Bureaucrat" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat	b0;
		std::cout << b0 << std::endl;
		Bureaucrat	b1(b0);
		std::cout << b1 << std::endl;
		Bureaucrat	b2("b2", 42);
		std::cout << b2 << std::endl;
		b0 = b2;
		std::cout << b0 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< " - ShrubberyCreationForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
	try {
		ShrubberyCreationForm	s0;
		std::cout << s0 << std::endl;
		ShrubberyCreationForm	s1(s0);
		std::cout << s1 << std::endl;
		ShrubberyCreationForm	s2("s2");
		std::cout << s2 << std::endl;
		s0 = s2;
		std::cout << s0 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< " - RobotomyRequestForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
    try{
		RobotomyRequestForm	r0;
		std::cout << r0 << std::endl;
		RobotomyRequestForm	r1(r0);
		std::cout << r1 << std::endl;
		RobotomyRequestForm	r2("r2");
		std::cout << r2 << std::endl;
		r0 = r2;
		std::cout << r0 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< " - PresidentialPardonForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
    try{
		PresidentialPardonForm	p0;
		std::cout << p0 << std::endl;
		PresidentialPardonForm	p1(p0);
		std::cout << p1 << std::endl;
		PresidentialPardonForm	p2("p2");
		p0 = p2;
		std::cout << p2 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
}

static void	testValidGrade() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Valid Bureaucrat grade ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< " - ShrubberyCreationForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat				b0("b0", 136);
		std::cout << b0 << std::endl;
		ShrubberyCreationForm	f0("home");
		std::cout << f0 << std::endl;
		b0.signForm(f0);
		b0.executeForm(f0);
		std::cout << f0 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< " - RobotomyRequestForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat				b1("b1", 44);
		std::cout << b1 << std::endl;
		RobotomyRequestForm		f1("target1");
		b1.signForm(f1);
		b1.executeForm(f1);
		std::cout << f1 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< " - PresidentialPardonForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat				b2("b2", 4);
		std::cout << b2 << std::endl;
		PresidentialPardonForm	f2("target2");
		b2.signForm(f2);
		b2.executeForm(f2);
		std::cout << f2 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
}

static void	testInvalidGradeToSign() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Invalid grade to sign the form ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< " - ShrubberyCreationForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat				b00("b00", 146);
		std::cout << b00 << std::endl;
		ShrubberyCreationForm	f00("home00");
		std::cout << f00 << std::endl;
		b00.signForm(f00);
		b00.executeForm(f00);
		std::cout << f00 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< " - RobotomyRequestForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat				b11("b11", 73);
		std::cout << b11 << std::endl;
		RobotomyRequestForm		f11("target11");
		std::cout << f11 << std::endl;
		b11.signForm(f11);
		b11.executeForm(f11);
		std::cout << f11 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< " - PresidentialPardonForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat				b22("b22", 26);
		std::cout << b22 << std::endl;
		PresidentialPardonForm	f22("target22");
		std::cout << f22 << std::endl;
		b22.signForm(f22);
		b22.executeForm(f22);
		std::cout << f22 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
}

static void	testInvalidGradeToExecute() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Invalid grade to execute the form ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< " - ShrubberyCreationForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat				b000("b000", 138);
		std::cout << b000 << std::endl;
		ShrubberyCreationForm	f000("home000");
		std::cout << f000 << std::endl;
		b000.signForm(f000);
		b000.executeForm(f000);
		std::cout << f000 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< " - RobotomyRequestForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat				b111("b111", 46);
		std::cout << b111 << std::endl;
		RobotomyRequestForm		f111("target111");
		std::cout << f111 << std::endl;
		b111.signForm(f111);
		b111.executeForm(f111);
		std::cout << f111 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< " - PresidentialPardonForm" << std::endl;	
	std::cout	<< "-----------------------------------------" << std::endl;
	try {
		Bureaucrat				b222("b222", 6);
		std::cout << b222 << std::endl;
		PresidentialPardonForm	f222("target222");
		std::cout << f222 << std::endl;
		b222.signForm(f222);
		b222.executeForm(f222);
		std::cout << f222 << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
	}
}
