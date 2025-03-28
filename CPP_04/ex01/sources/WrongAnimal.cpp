/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:50:05 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 14:08:39 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Default") {
	std::cout	<< "[ WrongAnimal ] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout	<< "[ WrongAnimal ] Parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	_type = other._type;
	std::cout	<< "[ WrongAnimal ] Copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout	<< "[ WrongAnimal ] Default destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout	<< "[ WrongAnimal ] Copy assigment operator called" << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType(void) const { 
	return (this->_type);
}

void		WrongAnimal::makeSound(void) const {
	std::cout	<< "[ WrongAnimal ] ... from: " << this->_type << std::endl;
}

