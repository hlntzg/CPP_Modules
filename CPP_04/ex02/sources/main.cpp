/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:36:14 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/28 15:38:54 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define SIZE 4

int	main(void) {

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Abstract class - or not! ]" << std::endl
				<< "-----------------------------------------" << std::endl
				<< "...a pointer or reference to an object of" << std::endl
				<< "its derived class (Dog, Cat) can be build" << std::endl
				<< "It is not possible to create an object of" << std::endl
				<< "itself directly. Since 'Animal' is now an" << std::endl
				<< "abstract class, can't be instantiated. :)" << std::endl
				<< "-----------------------------------------" << std::endl
				<< std::endl;

//	Animal	abstractAnimal;
//	Animal	abstractAnimal("Cat");

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Default ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	//const Animal*		animal = nullptr;
	const Animal*		cat = nullptr;
	const Animal*		dog = nullptr;

	try {
		
		//animal = new Animal();
		cat = new Cat();
		dog = new Dog();

		std::cout << "-----------------------------------------" << std::endl;
		
		//std::cout << "Animal type: " << animal->getType() << " " << std::endl;
		//animal->makeSound();
		std::cout << "Animal type: " << cat->getType() << " " << std::endl;
		cat->makeSound();
		std::cout << "Animal type: " << dog->getType() << " " << std::endl;
		dog->makeSound();

		std::cout << "-----------------------------------------" << std::endl;
		
		//delete animal;
		delete cat;
		delete dog;
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;

	//	delete animal;
		delete cat;
		delete dog;
		
		return (1);
	}

	std::cout	<< "---------[Default test is done!]---------" << std::endl
				<< std::endl;

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Array of Animal objects ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	
	const Animal*	a[SIZE] = {nullptr};
	int 			i = 0;
	try {
	
		for (; i < SIZE; i++)
		{
			if (i % 2 == 0)
				a[i] = new Dog();
			else
				a[i] = new Cat();
			//	a[i] = new Animal();
		}
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		for (int j = i - 1; j >= 0; j--)  
        	delete a[j];
		return (1);
	}
	std::cout << "-----------------------------------------" << std::endl;
	for (int i = 0; i < SIZE; i++)
		a[i]->makeSound();
	std::cout << "-----------------------------------------" << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete a[i];
	
	std::cout	<< "-[Array of Animal objects test is done!]-" << std::endl
				<< std::endl;
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ All tests done! ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	
	return (0);
}
