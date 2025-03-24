/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:53:58 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 11:54:00 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
	
	private:
		int					_rawValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);							// Default Constructor
		Fixed(const int value);					// Parameterized Constructor
		Fixed(const float value);				// Parameterized Constructor
		Fixed(const Fixed &other);				// Copy Constructor
		Fixed &operator=(const Fixed &other);	// Copy assignment operator overload
		~Fixed(void);							// Default Destructor

		// Member functions	
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		// Member functions - Comparison Operators overload
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		// Member functions - Arithmetic Operators overload
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		// Member functions - Increment/decrement Operators
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		// Static member functions
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

// Non-member function: overload of the insertion («) operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // overload of the insertion («) operator

#endif
