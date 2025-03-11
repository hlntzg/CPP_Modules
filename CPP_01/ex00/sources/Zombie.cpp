/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:28:07 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/11 12:02:33 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name) {
	setName(name);
	std::cout << "Zombie " << _name << " created." << std::endl;
	return ;
}

// Destructor
Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " destroyed." << std::endl;
	return ;
}

// Member function
void		Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}


void		Zombie::setName(std::string name) {
	_name = name;
	return ;
}

std::string	Zombie::getName() {
	return (_name);
}
