/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:35:17 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 11:21:02 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;		// Default Constructor - the Fixed class initializes its internal value to a default 0.
	Fixed	b(a);	// Copy Constructor - creates a new object (b) as a copy of an existing one (a).
	Fixed	c;		// Default Constructor called for new object (c).

	c = b;			// Copy Assignment Operator - assigns the values from one object (b) to another (c).
					// This differs from the copy constructor because it involves an already existing object (c).

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}
