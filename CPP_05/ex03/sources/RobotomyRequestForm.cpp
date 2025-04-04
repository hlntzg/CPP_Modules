/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:48:43 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/04 15:23:27 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("DefaultRobotomy") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

/**
 * std::time(0) returns the current time in seconds since the Unix epoch.
 * The value will vary each time std::time(0) is call.
 * std::srand(std::time(0)) seeds the random number generator with the current time, 
 * ensuring a different sequence of random numbers each time the program runs.
 */
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->getSignedForm() == false)
		throw AForm::FormNotSignedException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();

	std::cout << "[ Robotomy ] ... drilling noises ... [ volume: ▮▮▮▮▮▮▯▯ ]" << std::endl;

	srand(std::time(0));
	if (std::rand() % 2)
		std::cout << "[ Robotomy ] " << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "[ Robotomy ] " << this->_target << " robotomization failed." << std::endl;
}
