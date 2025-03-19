/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:24:36 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/19 16:24:47 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default Constructor
Zombie::Zombie(void) {
	std::cout << "Default constructor created." << std::endl;
}

// Destructor
Zombie::~Zombie(void) {
	std::cout << "Zombie " << _name << " destroyed." << std::endl;
}

// Member function
void		Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Member function
void		Zombie::setName(std::string name) {
	_name = name;
}

// Member function
std::string	Zombie::getName(void) {
	return (_name);
}
