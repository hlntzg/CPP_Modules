#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// default constructor
Fixed::Fixed(void) : _rawValue(0) {
	std::cout << "Default constructor called." << std::endl;
}
	
// parameterized Constructor
// convert value into fixed-point by shifting left by _fractionalBits (value multiplied by 2^_fractionalBits)
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called." << std::endl;
	_rawValue = value << _fractionalBits;
}

// parameterized Constructor
// convert value into fixed-point by multipling value by 2^_fractionalBits and round to the nearest integer
// note: left shift (<<) operator cannot be used on float
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called." << std::endl;
	_rawValue = roundf(value * (1 << _fractionalBits));
}

// copy constructor
// copies _rawValue from other to the new object.
Fixed::Fixed(const Fixed &other) : _rawValue(other._rawValue) {
	std::cout << "Copy constructor called." << std::endl;
//	_rawValue = other._rawValue;
	*this = other;
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other) {
		_rawValue = other.getRawBits();
	}
	return (*this);
}

// destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called." << std::endl;
}

int		Fixed::getRawBits(void) const {
	return (_rawValue);
}

void	Fixed::setRawBits(int const raw) {
	_rawValue = raw;
}

// converts the fixed-point value to a floating-point
float	Fixed::toFloat(void) const {
	return (static_cast<float>(_rawValue) / static_cast<float>(1 << _fractionalBits));
}

// converts the fixed-point value to a integer
int		Fixed::toInt(void) const {
	return (_rawValue >> _fractionalBits);
}

// non-member function
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
