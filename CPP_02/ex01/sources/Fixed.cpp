#include <Fixed.hpp>
#include <iostream>
#include <cmath>

// default constructor
Fixed::Fixed(void) : _rawValue(0) {
	std::cout << "Default constructor called." << std::endl;
}

		
// parameterized Constructor
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called." << std::endl;
	_rawValue = value << _fractionalBits;
}

// parameterized Constructor
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called." << std::endl;
	_rawValue = roundf(value * (1 << _fractionalBits));
}

// copy constructor
Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called." << std::endl;
	_rawValue = other.getRawBits();
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other) {
		_rawValue = other.getRawBits();
	}
	return (*this); // Required for chaining
}

// destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called." << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called." << std::endl;
	return (_rawValue);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called." << std::endl;
	_rawValue = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)_rawValue / (float)(1 << _fractionalBits));
}

int		Fixed::toInt(void) const {
	return (_rawValue >> _fractionalBits);
}

// non-member function
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
