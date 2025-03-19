/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:24:55 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/19 16:25:08 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	
	if (N <= 0) {
		std::cout << "Invalid number of zombies requested." << std::endl;
		return (nullptr);
	}
	
	Zombie*	horde = nullptr;
	
	try {
		horde = new Zombie[N];
	}
	catch (std::bad_alloc&) {
		std::cout << "Memory allocation failed." << std::endl;
		return (nullptr);
	}
	// Initialize each Zombie with the given name, adding index for uniqueness
	for (int i = 0; i < N; i++) {
		horde[i].setName(name + "_" + std::to_string(i + 1));
	}
	return (horde);
}
