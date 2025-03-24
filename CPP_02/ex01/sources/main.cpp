/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:03:03 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 11:18:23 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {

	Fixed			a;			// Default Constructor - the Fixed class initializes its internal value to a default 0.
	Fixed const		b(10);		// Parameterized Constructor - the Fixed class initializes itself by a integer value.
 	Fixed const		c(42.42f);	// Parameterized Constructor - the Fixed class initialized itself by a float value.
	Fixed const		d(b);		// Copy Constructor - create a new object (d) as a copy of an existing one (b).

	a = Fixed(1234.4321f);		// Copy Assigment Operator - assigns a new value to a.
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}
