/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:32:02 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/25 16:49:36 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->_name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
	std::cout << "Parameterized FragTrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "Copy FragTrap constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "Default FragTrap destructor called for " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "Copy assigment operator FragTrap called for " << _name << std::endl;
	return (*this);
}

/*
void	FragTrap::attack(const std::string& target) {
	if (!(this->_hitPoints))
		std::cout << "FragTrap " << _name << " doesn't have 'hit points'. " << _name << " cannot attack!" << std::endl;
	else if (!(this->_energyPoints))
		std::cout << "FragTrap " << _name << " doesn't have enough 'energy points'. " << _name << " cannot attack!" << std::endl;
	else {
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackPoints << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}
*/
void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " is now in 'high fives guys'  mode" << std::endl;
}
