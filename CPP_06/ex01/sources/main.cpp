/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:22:48 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/11 14:08:45 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0;0m"

int	main(void) {
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Default Serialization ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	Data	original;

	original.id = 1;
	original.name = "defaultName";
	std::cout << "[ Original Data*] " << &original << std::endl;	
    std::cout << "[ Original Data ] id = " << original.id << ", name = " << original.name << std::endl;
	std::cout << "-----------------------------------------" << std::endl;

	uintptr_t serialized = Serializer::serialize(&original);
	std::cout  << "converting pointer to the unsigned integer type ..." << std::endl;
	std::cout << "[ Serialized (uintptr_t)] " << serialized << std::endl;
	std::cout << "-----------------------------------------" << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout  << "converting unsigned integer type to a pointer to Data ..." << std::endl;
	std::cout << "[ Deserialized (Data*) ] " << deserialized << std::endl;
	std::cout << "-----------------------------------------" << std::endl;

    if (&original == deserialized) {
        std::cout << GREEN << "[✔] Success: Pointers are the same." << RESET << std::endl;
        std::cout << "[ Original Data ] id = " << original.id << ", name = " << original.name << ", address = " << &original << std::endl;
        std::cout << "[ Deserialized Data ] id = " << deserialized->id << ", name = " << deserialized->name << ", address = " << deserialized << std::endl;
    }
	else
        std::cout << RED << "[✗] Failure: The pointers are different." << RESET << std::endl;

	std::cout << "-----------------------------------------" << std::endl;
}
