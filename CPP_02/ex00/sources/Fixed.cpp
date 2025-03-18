#include <Fixed.hpp>
#include <iostream>

#define RESET "\e[0m"
#define CYAN "\e[0;36m"
#define MAGENTA "\e[0;35m"
#define GREEN "\e[0;32m"
#define	BLUE "\e[0;34m"	

// default constructor
Fixed::Fixed(void) : _rawValue(0) {
	std::cout << CYAN << "Default constructor called." << RESET << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed &other) {
	std::cout << MAGENTA << "Copy constructor called." << RESET << std::endl;
	_rawValue = other.getRawBits();
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << GREEN << "Copy assignment operator called." << RESET << std::endl;
	if (this != &other) {
		_rawValue = other.getRawBits();
	}
	return (*this); // Required for chaining
}

// destructor
Fixed::~Fixed(void) {
	std::cout << BLUE << "Destructor called." << RESET << std::endl;
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
