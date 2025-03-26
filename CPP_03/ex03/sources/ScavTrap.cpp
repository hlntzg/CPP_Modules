/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:32:02 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/26 14:07:05 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;
	std::cout << "[ ScavTrap ] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;
	std::cout << "[ ScavTrap ] Parameterized constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "[ ScavTrap ] Copy constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "[ ScavTrap ] Default destructor called for " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "[ ScavTrap ] Copy assigment operator called for " << _name << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target) {
	if (!(this->_hitPoints))
		std::cout << "[ ScavTrap ] " << _name << " doesn't have 'hit points'. " << _name << " cannot attack!" << std::endl;
	else if (!(this->_energyPoints))
		std::cout << "[ ScavTrap ] " << _name << " doesn't have enough 'energy points'. " << _name << " cannot attack!" << std::endl;
	else {
		std::cout << "[ ScavTrap ] " << _name << " attacks " << target << ", causing " << _attackPoints << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}

void	ScavTrap::guardGate(void) {
	std::cout << "[ ScavTrap ] " << _name << " is now in Gatekeeper mode" << std::endl;
}


/*
void	ScavTrap::attack(const std::string& target) {
	if (!(ClapTrap::_hitPoints))
		std::cout << "ScavTrap " << ClapTrap::_name << " doesn't have 'hit points'. " << ClapTrap::_name << " cannot attack!" << std::endl;
	else if (!(ClapTrap::_energyPoints))
		std::cout << "ScavTrap " << ClapTrap::_name << " doesn't have enough 'energy points'. " << ClapTrap::_name << " cannot attack!" << std::endl;
	else {
		std::cout << "ScavTrap " << ClapTrap::_name << " attacks " << target << ", causing " << ClapTrap::_attackPoints << " points of damage!" << std::endl;
		ClapTrap::_energyPoints -= 1;
	}
}
*/
