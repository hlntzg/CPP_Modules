/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:37:30 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/28 15:43:39 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "[ Cat ] Default constructor called" << std::endl;
	this->_type = "Cat";
	this->_catBrain = new Brain();
}

Cat::Cat(std::string type) : Animal(type) {
	this->_type = "Cat";
	this->_catBrain = new Brain();
	std::cout	<< "[ Cat ] Parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	this->_catBrain = new Brain(*other._catBrain);
	std::cout << "[ Cat ] Copy constructor called" << std::endl;
}

Cat::~Cat(void) {
	delete this->_catBrain;
	std::cout << "[ Cat ] Default destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	this->_catBrain = new Brain(*other._catBrain);
	std::cout << "[ Cat ] Copy assigment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const {
    std::cout << "[ Cat ] Meow meow ..." << std::endl;
}

Brain*	Cat::getBrain() {
	return (this->_catBrain != nullptr ? this->_catBrain : nullptr);
}
