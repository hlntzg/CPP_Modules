/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:37:52 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 09:21:56 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Default") {
	std::cout	<< "[ Animal ] Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout	<< "[ Animal ] Parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	_type = other._type;
//    if (this != &other)
//		*this = other;
	std::cout	<< "[ Animal ] Copy constructor called" << std::endl;
}

Animal::~Animal(void) {
	std::cout	<< "[ Animal ] Default destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout	<< "[ Animal ] Copy assigment operator called" << std::endl;
	return (*this);
}

std::string	Animal::getType(void) const { 
	return (this->_type);
}

void		Animal::makeSound(void) const {
	std::cout	<< "[ Animal ] ... " << std::endl;
}
