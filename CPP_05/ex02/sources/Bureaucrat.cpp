/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:10:35 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/04 09:38:17 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
	std::cout	<< "[ Bureaucrat ] Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name) {
	std::cout	<< "[ Bureaucrat ] Parameterized constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){
	std::cout	<< "[ Bureaucrat ] Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout	<< "[ Bureaucrat ] Default destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	std::cout	<< "[ Bureaucrat ] Copy assigment operator called" << std::endl;
	return (*this);
}

std::string		Bureaucrat::getName(void) const { 
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void			Bureaucrat::incrementGrade(void) {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void			Bureaucrat::decrementGrade(void) {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void			Bureaucrat::signForm(AForm &f) {
	try {
		f.beSigned(*this);
		std::cout << "[ Bureaucrat ] " << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "\e[0;31m" << "[ Bureaucrat ] " << this->_name << " couldn't sign " << f.getName() << ", because " << e.what() << "\e[0m" << std::endl;
//		throw;  // re-throw the exception to propagate it to the caller
	}
}

void			Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << "[ Bureaucrat ] " << this->_name << " successfully executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "\e[0;31m" << "[ Bureaucrat ] " << this->_name << " couldn't execute " << form.getName() << ", because " << e.what() << "\e[0m" << std::endl;
//		throw;  // re-throw the exception to propagate it to the caller
	}
}

const char*		Bureaucrat::GradeTooHighException::what() const noexcept /* throw()*/ {
    return ("[ Bureaucrat ] Grade too High!");
}

const char*		Bureaucrat::GradeTooLowException::what() const noexcept /*throw()*/ {
    return ("[ Bureaucrat ] Grade too Low!");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b) {
	out << "[ Bureaucrat ] " << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (out);
}
