/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:36:14 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/28 12:56:15 by hutzig           ###   ########.fr       */
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

	const Animal*		animal = nullptr;
	const Animal*		cat = nullptr;
	const Animal*		dog = nullptr;
	const WrongAnimal*	wrongAnimal = nullptr;
	const WrongAnimal*	wrongCat = nullptr;
	
	try {
		
		animal = new Animal();
		cat = new Cat();
		dog = new Dog();

		std::cout << "-----------------------------------------" << std::endl;
		
		std::cout << "Animal type: " << animal->getType() << " " << std::endl;
		animal->makeSound();
		std::cout << "Animal type: " << cat->getType() << " " << std::endl;
		cat->makeSound();
		std::cout << "Animal type: " << dog->getType() << " " << std::endl;
		dog->makeSound();

		std::cout << "-----------------------------------------" << std::endl;
		
		delete animal;
		delete cat;
		delete dog;

		std::cout << "-----------------------------------------" << std::endl;
		
		wrongAnimal = new WrongAnimal();
		wrongCat = new  WrongCat();

		std::cout << "-----------------------------------------" << std::endl;
		
		std::cout << "WrongAnimal type: " << wrongAnimal->getType() << " " << std::endl;
		wrongAnimal->makeSound();
		std::cout << "WrongAnimal type: " << wrongCat->getType() << " " << std::endl;
		wrongCat->makeSound();
		
		std::cout << "-----------------------------------------" << std::endl;
		
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
				<< "[ Test: Deep Copy ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	try {
		Cat	tom;
		Cat	copyTom(tom);
		Cat	copyOperatorTom = tom;

		Dog	toby;
		Dog	copyToby(toby);
		Dog	copyOperatorToby = toby;

		std::cout	<< "-----------------------------------------" << std::endl;
		std::cout	<< "[ Dog ] Default ideas:" << std::endl
					<< "toby brain ideas[0]: " << toby.getBrain()->getIdea(0) << std::endl
					<< "copyToby brain ideas[0]: " << copyToby.getBrain()->getIdea(0) << std::endl
					<< "copyOperatorToby brain ideas[0]: " << copyOperatorToby.getBrain()->getIdea(0) << std::endl;
		std::cout	<< "-----------------------------------------" << std::endl;
		std::cout	<< "[ Cat ] Default ideas:" << std::endl
					<< "tom brain ideas[1]: " << tom.getBrain()->getIdea(1) << std::endl
					<< "copyTom brain ideas[1]: " << copyTom.getBrain()->getIdea(1) << std::endl
					<< "copyOperatorTom brain ideas[1]: " << copyOperatorTom.getBrain()->getIdea(1) << std::endl;
		std::cout	<< "-----------------------------------------" << std::endl;
		std::cout	<< "[ Dog ] Change ideas:" << std::endl;
		std::cout	<< "toby change ideas[0]: newidea = 'I love my human!'" << std::endl;
		toby.getBrain()->setIdea(0, "I love my human!");
		std::cout	<< "copyToby change ideas[0]: newidea = 'Oh boy, I hope they're taking me for a walk today!'" << std::endl;
		copyToby.getBrain()->setIdea(0, "Oh boy, I hope they're taking me for a walk today!");
		std::cout	<< "copyOperatorToby change ideas[0]: newidea = 'What's that noise? I need to go check it out.'" << std::endl;
		copyOperatorToby.getBrain()->setIdea(0, "What's that noise? I need to go check it out.");
		std::cout	<< "-----------------------------------------" << std::endl;
		std::cout	<< "[ Cat ] Change ideas:" << std::endl;
		std::cout	<< "tom change ideas[1]: newidea = 'I know I am purrfect!'" << std::endl;
		tom.getBrain()->setIdea(1, "I know I am purrfect!");
		std::cout	<< "copyTom change ideas[1]: newidea = 'Oh my, a box! I'm sure I can fit inside it!'" << std::endl;
		copyTom.getBrain()->setIdea(1, "Oh my, a box! I'm sure I can fit inside it!");
		std::cout	<< "copyOperatorTom change ideas[1]: newidea = 'My humans think I'm cute, but I know I'm majestic!'" << std::endl;
		copyOperatorTom.getBrain()->setIdea(1, "My humans think I'm cute, but I know I'm majestic!");
		std::cout	<< "-----------------------------------------" << std::endl
					<< "[ Testing deep copies ...]" << std::endl
					<< "-----------------------------------------" << std::endl;
		std::cout	<< "toby brain ideas[0]: " << toby.getBrain()->getIdea(0) << std::endl
					<< "copyToby brain ideas[0]: " << copyToby.getBrain()->getIdea(0) << std::endl
					<< "copyOperatorToby brain ideas[0]: " << copyOperatorToby.getBrain()->getIdea(0) << std::endl;
		std::cout	<< "-----------------------------------------" << std::endl;
		std::cout	<< "tom brain ideas[1]: " << tom.getBrain()->getIdea(1) << std::endl
					<< "copyTom brain ideas[1]: " << copyTom.getBrain()->getIdea(1) << std::endl
					<< "copyOperatorTom brain ideas[1]: " << copyOperatorTom.getBrain()->getIdea(1) << std::endl;
		std::cout	<< "-----------------------------------------" << std::endl;

	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return (1);
	}
	std::cout	<< "-------[Deep Copy test is done!]------" << std::endl
				<< std::endl;
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ All tests done! ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	return (0);
}
