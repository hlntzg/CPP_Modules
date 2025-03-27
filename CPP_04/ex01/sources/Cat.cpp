/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:37:30 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 17:17:10 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	this->_type = "Cat";
	try {
		this->_catBrain = new Brain();
	}
	catch (const std::bad_alloc &e) {
		std::cerr << "[ Cat ] Memory allocation failed: " << e.what() << std::endl;
		// delete this->_catBrain;
	}
	std::cout << "[ Cat ] Default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	this->_type = "Cat";
	std::cout	<< "[ Cat ] Parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
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
	std::cout << "[ Cat ] Copy assigment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const {
    std::cout << "[ Cat ] Meow meow ..." << std::endl;
}
