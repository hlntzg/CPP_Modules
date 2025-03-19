#include "Fixed.hpp"

// default constructor
Fixed::Fixed(void) : _rawValue(0) {
	std::cout << "Default constructor called." << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed &other) : _rawValue(other._rawValue) {
	std::cout << "Copy constructor called." << std::endl;
	//_rawValue = other.getRawBits();
	*this = other;
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

// public member functions
int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called." << std::endl;
	return (_rawValue);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called." << std::endl;
	_rawValue = raw;
}
