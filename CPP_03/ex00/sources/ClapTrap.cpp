/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:47:39 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/25 12:24:06 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackPoints(0) {
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackPoints (0) {
	std::cout << "Parameterized ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "Copy ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Default ClapTrap destructor called for " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackPoints = other._attackPoints;
	}
	std::cout << "Copy assigment operator ClapTrap called for " << _name << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (!_hitPoints)
		std::cout << "\tClapTrap " << _name << " doesn't have 'hit points'. " << _name << " cannot attack!" << std::endl;
	else if (!_energyPoints)
		std::cout << "\tClapTrap " << _name << " doesn't have enough 'energy points'. " << _name << " cannot attack!" << std::endl;
	else {
		std::cout << "\tClapTrap " << _name << " attacks " << target << ", causing " << _attackPoints << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!_hitPoints)
		std::cout << "\tClapTrap " << _name << " doesn't have 'hit points'. " << _name << " cannot take damage!" << std::endl;
	else if (amount >= _hitPoints) {
		std::cout << "\tClapTrap " << _name << " doesn't have enough 'hit points'. " << _name << " has lost " << amount << " 'hit points'!"<< std::endl;
		_hitPoints = 0;
	}
	else {
		std::cout << "\tClapTrap " << _name << " has lost " << amount << " 'hit points'!" << std::endl;
		_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!_hitPoints)
		std::cout << "\tClapTrap " << _name << " doesn't have 'hit points'. " << _name << " cannot be repaired" << std::endl;
	else if (!_energyPoints)
		std::cout << "\tClapTrap " << _name << " doesn't have enough 'energy points'. " << _name << " cannot be repaired" << std::endl;
	else {
		std::cout << "\tClapTrap " << _name << " has been repaired by " << amount << " 'hit points'!" << std::endl;
		_hitPoints += amount;
		_energyPoints -= 1;
	}
}
