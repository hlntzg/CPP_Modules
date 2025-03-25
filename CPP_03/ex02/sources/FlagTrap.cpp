/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:32:02 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/25 16:49:36 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void) : ClapTrap() {
	this->_name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	std::cout << "Default FlagTrap constructor called" << std::endl;
}

FlagTrap::FlagTrap(const std::string name) : ClapTrap(name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	std::cout << "Parameterized FlagTrap constructor called for " << _name << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap &other) : ClapTrap(other) {
	std::cout << "Copy FlagTrap constructor called for " << _name << std::endl;
}

FlagTrap::~FlagTrap(void) {
	std::cout << "Default FlagTrap destructor called for " << _name << std::endl;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "Copy assigment operator FlagTrap called for " << _name << std::endl;
	return (*this);
}

/*
void	FlagTrap::attack(const std::string& target) {
	if (!(this->_hitPoints))
		std::cout << "FlagTrap " << _name << " doesn't have 'hit points'. " << _name << " cannot attack!" << std::endl;
	else if (!(this->_energyPoints))
		std::cout << "FlagTrap " << _name << " doesn't have enough 'energy points'. " << _name << " cannot attack!" << std::endl;
	else {
		std::cout << "FlagTrap " << _name << " attacks " << target << ", causing " << _attackPoints << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}
*/
void	FlagTrap::highFivesGuys(void) {
	std::cout << "FlagTrap " << _name << " is now in 'high fives guys'  mode" << std::endl;
}
