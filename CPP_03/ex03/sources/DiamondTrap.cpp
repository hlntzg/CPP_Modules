/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:45:23 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/26 16:00:28 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name("default_Diamond") {
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "[ DiamondTrap ] Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "[ DiamondTrap ] Parameterized constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    _name = other._name;
	std::cout << "[ DiamondTrap ] Copy constructor called for " << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "[ DiamondTrap ] Default destructor called for " << this->_name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		ClapTrap::operator=(other);
	}
	std::cout << "[ DiamondTrap ] Copy assigment operator called" << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI(void) {
	
	std::cout	<< "[ DiamondTrap ] name: " << this->_name << std::endl
				<< "[ ClapTrap ]    name: " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::howManyPoints(void) {
	
	std::cout	<< "[ DiamondTrap ] " << _name << " 'hit points':    " << this->_hitPoints << std::endl
				<< "[ DiamondTrap ] " << _name << " 'energy points': " << this->_energyPoints << std::endl
				<< "[ DiamondTrap ] " << _name << " 'attack damage': " << this->_attackDamage << std::endl;
}
