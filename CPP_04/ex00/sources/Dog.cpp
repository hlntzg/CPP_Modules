/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:37:09 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 09:21:43 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	this->_type = "Dog";
	std::cout	<< "[ Dog ] Default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	this->_type = "Dog";
	std::cout	<< "[ Dog ] Parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout	<< "[ Dog ] Copy constructor called" << std::endl;
}

Dog::~Dog(void) {
	std::cout	<< "[ Dog ] Default destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout	<< "[ Dog ] Default destructor called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const {
    std::cout << "[ Dog ] Woof woof ..." << std::endl;
}
