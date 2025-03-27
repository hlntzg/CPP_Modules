/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:15:35 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 09:25:53 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout	<< "[ WrongCat ] Default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	this->_type = "WrongCat";
	std::cout	<< "[ WrongCat ] Parameterized constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout	<< "[ WrongCat ] Copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout	<< "[ WrongCat ] Default destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout	<< "[ WrongCat ] Default destructor called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const {
    std::cout << "[ WrongCat ] Meow meow meow meow ..." << std::endl;
}

