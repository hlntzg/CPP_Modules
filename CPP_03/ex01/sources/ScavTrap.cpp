/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:32:02 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/25 16:09:45 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;
	std::cout << "Parameterized ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "Copy ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Default ScavTrap destructor called for " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "Copy assigment operator ScavTrap called for " << _name << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target) {
	if (!(this->_hitPoints))
		std::cout << "ScavTrap " << _name << " doesn't have 'hit points'. " << _name << " cannot attack!" << std::endl;
	else if (!(this->_energyPoints))
		std::cout << "ScavTrap " << _name << " doesn't have enough 'energy points'. " << _name << " cannot attack!" << std::endl;
	else {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackPoints << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode" << std::endl;
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

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << ClapTrap::_name << " is now in Gatekeeper mode" << std::endl;
}*/
