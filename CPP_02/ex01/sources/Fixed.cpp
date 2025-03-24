/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:12:03 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 11:42:49 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawValue(0) {
	std::cout << "Default constructor called" << std::endl;
}
	
/**
 * Parameterized Constructor (int) - Initializes a Fixed object by converting an
 * integer value into a fixed-point by shifting left by the number of fractional bits.
 * The input integer value is multiplied by 2^_fractionalBits.
 */
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_rawValue = value << _fractionalBits;
}

/**
 * Parameterized Constructor (float) - Initializes a Fixed object by converting a
 * floating-point value into a fixed-point. The value is multiplied by 2^_fractionalBits
 * and rounded to the nearest integer.
 * Note: The left shift (<<) operator cannot be used on floating-point numbers.
 */
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_rawValue = roundf(value * (1 << _fractionalBits));
}

/**
 * Copy Constructor - Initializes a new Fixed object as a copy of another Fixed object. 
 * The _rawValue is copied from the existing object to the new one.
 */
Fixed::Fixed(const Fixed &other) : _rawValue(other._rawValue) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/**
 * Copy Assignment Operator - This operator overload is used to copy the values
 * from one Fixed object to another. The _rawValue is assigned from the other object if the 
 * two objects are not the same (this != &other), handling self-assignment.
 */
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_rawValue = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	return (_rawValue);
}

void	Fixed::setRawBits(int const raw) {
	_rawValue = raw;
}

/**
 * toFloat - Converts the internal fixed-point value to a floating-point value
 * by dividing the raw value by 2^_fractionalBits.
 */
float	Fixed::toFloat(void) const {
	return (static_cast<float>(_rawValue) / static_cast<float>(1 << _fractionalBits));
}

/**
 * toInt - Converts the internal fixed-point value to an integer by right-shifting the raw value 
 * by the number of fractional bits, truncating the fixed-point value (floor operation).
 */
int		Fixed::toInt(void) const {
	return (_rawValue >> _fractionalBits);
}

/**
 * Non-member function: stream insertion operator (<<)
 * This function allows us to output a Fixed object directly to an output stream, such as std::cout.
 * It prints the floating-point equivalent of the fixed-point number.
 */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
