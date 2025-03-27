/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:47:39 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 10:55:59 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "[ ClapTrap ] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage (0) {
	std::cout << "[ ClapTrap ] Parameterized constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "[ ClapTrap ] Copy constructor called for " << this->_name << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "[ ClapTrap ] Default destructor called for " << this->_name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "[ ClapTrap ] Copy assigment operator called" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (!this->_hitPoints)
		std::cout << "[ ClapTrap ] " << this->_name << " doesn't have 'hit points'. " << this->_name << " cannot attack!" << std::endl;
	else if (!this->_energyPoints)
		std::cout << "[ ClapTrap ] " << this->_name << " doesn't have enough 'energy points'. " << this->_name << " cannot attack!" << std::endl;
	else {
		std::cout << "[ ClapTrap ] " << this-> _name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!this->_hitPoints)
		std::cout << "[ ClapTrap ] " << this->_name << " doesn't have 'hit points'. " << this->_name << " cannot take damage!" << std::endl;
	else if (amount >= this->_hitPoints) {
		std::cout << "[ ClapTrap ] " << this->_name << " doesn't have enough 'hit points'. " << this->_name << " has lost " << amount << " 'hit points'!"<< std::endl;
		this->_hitPoints = 0;
	}
	else {
		std::cout << "[ ClapTrap ] " << this->_name << " has lost " << amount << " 'hit points'!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->_hitPoints)
		std::cout << "[ ClapTrap ] " << this->_name << " doesn't have 'hit points'. " << this->_name << " cannot be repaired!" << std::endl;
	else if (!this->_energyPoints)
		std::cout << "[ ClapTrap ] " << this->_name << " doesn't have enough 'energy points'. " << this->_name << " cannot be repaired!" << std::endl;
	else {
		std::cout << "[ ClapTrap ] " << this->_name << " has been repaired by " << amount << " 'hit points'!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
}
