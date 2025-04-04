/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:28:19 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/04 15:22:19 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("DefaultAForm"), _signedForm(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout	<< "[ AForm ] Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const unsigned int signGrade, const unsigned int executeGrade) : _name(name), _signedForm(false), _gradeToSign(signGrade), _gradeToExecute(executeGrade) {
	std::cout	<< "[ AForm ] Parameterized constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signedForm(other._signedForm), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout	<< "[ AForm ] Copy constructor called" << std::endl;
}

AForm::~AForm(void) {
	std::cout	<< "[ AForm ] Default destructor called" << std::endl;
}

AForm	&AForm::operator=(const AForm &other) {
	if (this != &other) {
		this->_signedForm = other._signedForm;
	}
	std::cout	<< "[ AForm ] Copy assigment operator called" << std::endl;
	return (*this);
}

std::string		AForm::getName(void) const { 
	return (this->_name);
}

bool			AForm::getSignedForm(void) const {
	return (this->_signedForm);
}

unsigned int	AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

unsigned int	AForm::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

void			AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signedForm = true;
}

const char*		AForm::GradeTooHighException::what() const noexcept {
    return ("... Grade too High!");
}

const char*		AForm::GradeTooLowException::what() const noexcept {
    return ("... Grade too Low!");
}

const char*		AForm::FormNotSignedException::what() const noexcept {
    return ("... Form not signed!");
}

std::ostream	&operator<<(std::ostream &out, const AForm &f) {
	out << "[ AForm ] " << f.getName() << ", signed status: ";
	if (f.getSignedForm())
		out << "[✔] form is signed" << std::endl;
	else
		out << "[✗] form is not signed" << std::endl;
	out	<< "[ AForm ] " << f.getName() << ", required grade to sign: " << f.getGradeToSign() << std::endl
		<< "[ AForm ] " << f.getName() << ", required grade to execute: " << f.getGradeToExecute();
	return (out);
}
