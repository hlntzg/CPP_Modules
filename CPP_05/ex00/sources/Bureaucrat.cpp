/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:10:35 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/31 14:40:28 by hutzig           ###   ########.fr       */
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
//		this->_name = other._name;
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

const char*		Bureaucrat::GradeTooHighException::what() const throw() {
    return ("[ Bureaucrat ] Grade too High!");
}

const char*		Bureaucrat::GradeTooLowException::what() const throw() {
    return ("[ Bureaucrat ] Grade too Low!");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b) {
	out << "[ Bureaucrat ] " << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (out);
}
