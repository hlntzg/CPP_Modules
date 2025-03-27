/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:36:14 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 17:56:03 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define SIZE 10

int	main(void) {

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ I don’t want to set the world on fire ]" << std::endl
				<< "-----------------------------------------" << std::endl
				<< std::endl;
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Default ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	const Animal*	animal = nullptr;
	const Animal*	cat = nullptr;
	const Animal*	dog = nullptr;
	const Animal*	wrongAnimal = nullptr;
	const Animal*	wrongCat = nullptr;
	
	try {
		animal = new Animal();
		cat = new Cat();
		dog = new Dog();

		std::cout << "Animal type: " << animal->getType() << " " << std::endl;
		animal->makeSound();
		std::cout << "Animal type: " << cat->getType() << " " << std::endl;
		cat->makeSound();
		std::cout << "Animal type: " << dog->getType() << " " << std::endl;
		dog->makeSound();

		delete animal;
		delete cat;
		delete dog;

		std::cout << "-----------------------------------------" << std::endl;
		wrongAnimal = new WrongAnimal();
		wrongCat = new  WrongCat();

		std::cout << "WrongAnimal type: " << wrongAnimal->getType() << " " << std::endl;
		wrongAnimal->makeSound();
		std::cout << "WrongAnimal type: " << wrongCat->getType() << " " << std::endl;
		wrongCat->makeSound();
		
		delete wrongAnimal;
		delete wrongCat;
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;

		delete animal;
		delete cat;
		delete dog;
		delete wrongAnimal;
		delete wrongCat;
		return (1);
	}

	std::cout	<< "---------[Default test is done!]---------" << std::endl;

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Array of Animal objects ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	
	const Animal*	a[SIZE];
	
	try {
			for (int i = 0; i < SIZE; i++)
			{
				if (i % 2 == 0)
					a[i] = new Dog();
				else
					a[i] = new Cat();
			}
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		for (int j = 0; j < SIZE; j++) 
			delete a[j];
		// need to delete something before i "new" fails?
		return (1);
	}
	std::cout << "-----------------------------------------" << std::endl;
	for (int i = 0; i < SIZE; i++)
		a[i]->makeSound();
	std::cout << "-----------------------------------------" << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete a[i];
	
	std::cout	<< "-[Array of Animal objects test is done!]-" << std::endl;

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Deep Copy ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	try {



	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;


		return (1);
	}

	std::cout << "-------[Deep Copy test is done!]------" << std::endl;

	return (0);
}
