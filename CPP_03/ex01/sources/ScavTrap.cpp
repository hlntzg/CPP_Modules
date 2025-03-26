/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:32:02 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/26 16:10:43 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "[ ScavTrap ] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "[ ScavTrap ] Parameterized constructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "[ ScavTrap ] Copy constructor called for " << this->_name << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "[ ScavTrap ] Default destructor called for " << this->_name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "[ ScavTrap ] Copy assigment operator called" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target) {
	if (!(this->_hitPoints))
		std::cout << "[ ScavTrap ] " << this->_name << " doesn't have 'hit points'. " << this->_name << " cannot attack!" << std::endl;
	else if (!(this->_energyPoints))
		std::cout << "[ ScavTrap ] " << this->_name << " doesn't have enough 'energy points'. " << this->_name << " cannot attack!" << std::endl;
	else {
		std::cout << "[ ScavTrap ] " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ScavTrap::guardGate(void) {
	std::cout << "[ ScavTrap ] " << this->_name << " is now in Gatekeeper mode" << std::endl;
}
