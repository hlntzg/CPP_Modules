/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:54:06 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 13:39:18 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#if 1
int	main(void) {

	// Default Constructor - Initializes 'a' with a default value (0).
	Fixed		a;	
	
	// Parameterized Constructor - Creating a Fixed object 'b' which is the result of multiplying Fixed(5.05f) with Fixed(2)
    // This will call the constructor for Fixed(5.05f), and the multiplication operator is likely overloaded.
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	
	return (0);
}

#endif 

#if 0
static void testComparisonOperators(const Fixed& a, const Fixed& b) {
	std::cout	<< "-----------------------------------------" << std::endl;
    std::cout	<< "Comparing " << a << " and " << b << ":" << std::endl
				<< "\ta > b: " << (a > b) << std::endl
				<< "\ta < b: " << (a < b) << std::endl
				<< "\ta >= b: " << (a >= b) << std::endl
				<< "\ta <= b: " << (a <= b) << std::endl
				<< "\ta == b: " << (a == b) << std::endl
				<< "\ta != b: " << (a != b) << std::endl;
}

static void testArithmeticOperators(const Fixed& a, const Fixed& b) {
	std::cout	<< "-----------------------------------------" << std::endl;
    std::cout	<< "Arithmetic operations with " << a << " and " << b << ":" << std::endl
				<< "\ta + b = " << (a + b) << std::endl
				<< "\ta - b = " << (a - b) << std::endl
				<< "\ta * b = " << (a * b) << std::endl
				<< "\ta / b = " << (a / b) << std::endl;
}

static void testIncrementDecrement(Fixed& b) {
	std::cout	<< "-----------------------------------------" << std::endl;
    std::cout	<< "Testing increment on " << b << ":" << std::endl
				<< "\tpre-increment: " << ++b << std::endl
				<< "\tpost-increment: " << b++ << " (b: " << b << ")" << std::endl
				<< "Testing decrement on " << b << ":" << std::endl
				<< "\tpre-decrement: " << --b << std::endl
				<< "\tpost-decrement: " << b-- << " (b: " << b << ")" << std::endl;
}

static void testMinMax(const Fixed& a, const Fixed& b) {
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< "Testing member function min for " << a << " and " << b << ":" << std::endl
				<< "\tMin value is: " << Fixed::min(a, b) << std::endl
				<< "Testing member function max for " << a << " and " << b << ":" << std::endl
				<< "\tMax value is: " << Fixed::max(a, b) << std::endl;
}

static void testRawBits(Fixed& a) {
	std::cout	<< "-----------------------------------------" << std::endl;
    std::cout	<< "Raw bits of " << a << ": " << a.getRawBits() << std::endl;
    a.setRawBits(256);
    std::cout << "After setting raw bits: " << a.getRawBits() << std::endl;
}

int main(void) {

    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

	std::cout	<< "-----------------------------------------" << std::endl;
    std::cout	<< "Initial values:" << std::endl
				<< "\ta: " << a << std::endl
				<< "\tb: " << b << "\t\t(Fixed from int)" <<std::endl
				<< "\tc: " << c << "\t(Fixed from float)" << std::endl
				<< "\td: " << d << "\t\t(copy of b)" << std::endl;

	testComparisonOperators(a, b);
	testArithmeticOperators(a, b);
    testIncrementDecrement(b);
	testMinMax(a, b);
	testRawBits(a);

    return (0);
}

#endif
