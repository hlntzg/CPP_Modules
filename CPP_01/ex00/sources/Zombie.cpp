/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:28:07 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/11 14:13:17 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name) {
	setName(name);
	std::cout << "Zombie " << _name << " created." << std::endl;
}

// Destructor
Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " destroyed." << std::endl;
}

// Member function
void		Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void		Zombie::setName(std::string name) {
	_name = name;
}

std::string	Zombie::getName() {
	return (_name);
}
