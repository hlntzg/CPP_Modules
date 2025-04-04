/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:48:57 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/04 14:17:29 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::cout	<< "[ Intern ] Default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	(void)other;
	std::cout	<< "[ Intern ] Copy constructor called" << std::endl;
}

Intern::~Intern(void) {
	std::cout	<< "[ Intern ] Default destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;	
	std::cout	<< "[ Intern ] Copy assigment operator called" << std::endl;
	return (*this);
}

AForm*	Intern::makeShrubberyForm(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyForm(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialForm(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string &name, const std::string &target) {
	std::string	typeForm[3] = {"shrubbery", "robotomy", "presidential"};

	// Array of functions pointers to create forms accordanly 
	AForm* (*_form[3])(const std::string &target) = {	&Intern::makeShrubberyForm,
														&Intern::makeRobotomyForm,
														&Intern::makePresidentialForm };

	for (int i = 0; i < 3; i++) {
		if (name == typeForm[i]) {
			std::cout << "[ Intern ] Intern creates " << typeForm[i] << std::endl;
			return (_form[i](target));
		}
	}
	// If no match typeForm and form name was found, throw an exception
	throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const noexcept {
    return ("Form not found: Type of form specified cannot be created.");
}
