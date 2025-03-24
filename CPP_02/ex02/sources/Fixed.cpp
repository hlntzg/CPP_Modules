/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:06:18 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 12:08:09 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawValue(0) {}
	
Fixed::Fixed(const int value) {
	_rawValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	_rawValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) : _rawValue(other._rawValue) {}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		_rawValue = other._rawValue;
	}
	return (*this);
}

Fixed::~Fixed(void) {}

int		Fixed::getRawBits(void) const {
	return (_rawValue);
}

void	Fixed::setRawBits(int const raw) {
	_rawValue = raw;
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(_rawValue) / static_cast<float>(1 << _fractionalBits));
}

int		Fixed::toInt(void) const {
	return (_rawValue >> _fractionalBits);
}

// Member functions - Comparison Operators overload
bool	Fixed::operator>(const Fixed &other) const	{ return (_rawValue > other.getRawBits()); }
bool	Fixed::operator<(const Fixed &other) const	{ return (_rawValue < other.getRawBits()); }
bool	Fixed::operator>=(const Fixed &other) const	{ return (_rawValue >= other.getRawBits()); }
bool	Fixed::operator<=(const Fixed &other) const	{ return (_rawValue <= other.getRawBits()); }
bool	Fixed::operator==(const Fixed &other) const	{ return (_rawValue == other.getRawBits()); }
bool	Fixed::operator!=(const Fixed &other) const	{ return (_rawValue != other.getRawBits());	}

// Member functions - Arithmetic Operators overload
Fixed	Fixed::operator+(const Fixed &other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed	Fixed::operator-(const Fixed &other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed	Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed	Fixed::operator/(const Fixed &other) const {
	if (other._rawValue == 0) {
		std::cerr << "Error: Division by Zero!" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

// Member functions - (pre-post)Increment/(pre-post)decrement Operators
Fixed	&Fixed::operator++(void) {
	_rawValue++;
	return(*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	original(*this);
	++(*this);
	return (original);
}

Fixed	&Fixed::operator--(void) {
	_rawValue--;
	return(*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	original(*this);
	--(*this);
	return (original);
}

// Static member functions
Fixed		&Fixed::min(Fixed &a, Fixed &b)				{ return (a.operator<(b) ? a : b); }
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) { return (a.operator<(b) ? a : b); }
Fixed		&Fixed::max(Fixed &a, Fixed &b)				{ return (a.operator>(b) ? a : b); }
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) { return (a.operator>(b) ? a : b); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
