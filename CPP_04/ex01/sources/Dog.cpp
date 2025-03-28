/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:37:09 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/28 15:43:46 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	std::cout	<< "[ Dog ] Default constructor called" << std::endl;
	this->_type = "Dog";
	this->_dogBrain = new Brain();
}

Dog::Dog(std::string type) : Animal(type) {
	this->_type = "Dog";
	this->_dogBrain = new Brain();
	std::cout	<< "[ Dog ] Parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	this->_dogBrain = new Brain(*other._dogBrain);
	std::cout	<< "[ Dog ] Copy constructor called" << std::endl;
}

Dog::~Dog(void) {
	delete this->_dogBrain;
	std::cout	<< "[ Dog ] Default destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	this->_dogBrain = new Brain(*other._dogBrain);
	std::cout	<< "[ Dog ] Default destructor called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const {
    std::cout << "[ Dog ] Woof woof ..." << std::endl;
}

Brain*	Dog::getBrain() {
	return (this->_dogBrain != nullptr ? this->_dogBrain : nullptr);
}
