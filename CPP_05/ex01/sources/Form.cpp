/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:28:19 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/31 16:31:44 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("DefaultForm"), _signedForm(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout	<< "[ Form ] Default constructor called" << std::endl;
}

Form::Form(const std::string name, const unsigned int signGrade, const unsigned int executeGrade) : _name(name), _signedForm(false), _gradeToSign(signGrade), _gradeToExecute(executeGrade) {
	std::cout	<< "[ Form ] Parameterized constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signedForm(other._signedForm), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout	<< "[ Form ] Copy constructor called" << std::endl;
}

Form::~Form(void) {
	std::cout	<< "[ Form ] Default destructor called" << std::endl;
}

Form	&Form::operator=(const Form &other) {
	if (this != &other) {
		this->_signedForm = other._signedForm;
	}
	std::cout	<< "[ Form ] Copy assigment operator called" << std::endl;
	return (*this);
}

std::string		Form::getName(void) const { 
	return (this->_name);
}

bool			Form::getSignedForm(void) const {
	return (this->_signedForm);
}

unsigned int	Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

unsigned int	Form::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

void			Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signedForm = true;
}
/*

Form::GradeTooHighException::GradeTooHighException(const std::string& message) : message_(message) {}

// Here the function needs to return "const char*" type value, but message_
// is a std::string type, so here need use "c_str()" to change message_ to "const char*"
const char* Form::GradeTooHighException::what() const noexcept { return message_.c_str(); }

Form::GradeTooLowException::GradeTooLowException(const std::string& message) : message_(message){}

const char* Form::GradeTooLowException::what() const noexcept { return message_.c_str(); }

*/
const char*		Form::GradeTooHighException::what() const throw() {
    return ("[ Form ] Grade too High!");
}

const char*		Form::GradeTooLowException::what() const throw() {
    return ("[ Form ] Grade too Low!");
}

std::ostream	&operator<<(std::ostream &out, const Form &f) {
	out << "[ Form ] " << f.getName() << ", signed: " << f.getSignedForm() << std::endl
		<< "[ form ] " << f.getName() << ", required grade to sign: " << f.getGradeToSign() << std::endl
		<< "[ form ] " << f.getName() << ", required grade to execute: " << f.getGradeToExecute() << std::endl;
	return (out);
}
