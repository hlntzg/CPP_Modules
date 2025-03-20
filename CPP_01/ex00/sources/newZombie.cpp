/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:23:39 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/20 09:55:32 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name) {
	Zombie*	zombieHeap = nullptr;
	try {
		zombieHeap = new Zombie(name);
	}
	catch (std::bad_alloc&) {
		std::cout << "Memory allocation failed." << std::endl;
		return (nullptr);
	}
	return (zombieHeap);
}

