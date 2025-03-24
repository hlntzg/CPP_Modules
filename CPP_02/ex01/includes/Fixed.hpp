/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:01:39 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 11:39:08 by hutzig           ###   ########.fr       */
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
		Fixed(const Fixed& other);				// Copy Constructor
		Fixed &operator=(const Fixed &other);	// Copy assignment operator overload
		~Fixed(void);							// Default Destructor
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;			// Member function - Converts the fixed-point value to a floating-point value
		int		toInt(void) const;				// Member function - Converts the fixed-point value to an integer value
};

// Non-member function: overload of the insertion («) operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
