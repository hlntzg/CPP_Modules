/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:32:02 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/26 13:58:45 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	std::cout << "[ FragTrap ] Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	std::cout << "[ FragTrap ] Parameterized constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "[ FragTrap ] Copy constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "[ FragTrap ] Default destructor called for " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "[ FragTrap ] Copy assigment operator called for " << _name << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "[ FragTrap ] " << _name << " is now in 'high fives guys'  mode" << std::endl;
}
