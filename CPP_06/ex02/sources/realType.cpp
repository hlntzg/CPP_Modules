/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:39:51 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/11 16:51:14 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "realType.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/**
 * Randomly creates and returns an instance of A, B, or C(derived from Base) using `std::rand()`.
 * The returned object is allocated on the heap and must be deleted by the caller.
 */
Base*	generate(void) {
    
	std::srand(std::time(0));
	int	i = std::rand() % 3;

	switch(i) {
		case 0:
			std::cout << "[ Generator randomly instantiate A ]" << std::endl;
			return (new A);
		case 1:
			std::cout << "[ Generator randomly instantiate B ]" << std::endl;
			return (new B);
		case 2:
			std::cout << "[ Generator randomly instantiate C ]" << std::endl;
			return (new C);
		default:
			return nullptr;
	}
}

/**
 * This function identifies the actual derived type of the object pointed to by a Base pointer.
 * Uses dynamic_cast to safely downcast and determine the real type (A, B, or C). 
 */
void	identify(Base* p) {

	if (!p) {
		std::cout << "Error: p pointer is an nullptr." << std::endl;
		return ;
	}
	
	std::cout << "[ Identify ] The actual type of object pointed to by 'p' is: ";
    // Try downcasting to each derived type
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

/**
 * This function identifies the actual derived type of the object referenced by a Base reference.
 * Since references can't be null, dynamic_cast throws std::bad_cast on failure.
 * It uses nested try-catch blocks to attempt the cast to a specific derived type (A, B, and C).
 */ 
void	identify(Base& p) {

	std::cout << "[ Identify ] The actual type of object referenced by 'p' is: ";

    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &e) {
        try {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::bad_cast &e) {
            try {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::bad_cast &e) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}
