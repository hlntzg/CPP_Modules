/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:25:50 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/11 16:45:08 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "realType.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static void	testDefault();
static void testIdentifyPointers();
static void	testIdentifyReferences();

int	main(void) {

	testDefault();
	testIdentifyPointers();
	testIdentifyReferences();
	return (0);
}

static void	testDefault(void) {

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Default generate and idenfity ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    
	Base *base = generate();
    identify(base);
    identify(*base);

    delete base;
}

static void	testIdentifyPointers() {
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Identify type pointed to by 'p' ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	Base*	a = new A();
    std::cout << " - Pointer to A instance:" << std::endl;
	identify(a);

	Base*	b = new B();
    std::cout << " - Pointer to B instance:" << std::endl;
	identify(b);
	
	Base*	c = new C();
	std::cout << " - Pointer to C instance:" << std::endl;
	identify(c);

	delete a;
	delete b;
	delete c;
}

static void testIdentifyReferences(void) {
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Identify type referenced by 'p' ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	A	a;
	std::cout << " - Reference to A instance:" << std::endl;
	identify(a);

	B	b;
	std::cout << " - Reference to B instance:" << std::endl;
	identify(b);
	
	C	c;
	std::cout << " - Reference to C instance:" << std::endl;
	identify(c);
	
	std::cout << "-----------------------------------------" << std::endl;
}
