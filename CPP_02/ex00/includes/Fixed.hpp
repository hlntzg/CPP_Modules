/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:42:00 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 09:42:11 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {
	
	private:
		int					_rawValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);							// Default Constructor
		Fixed(const Fixed& other);				// Copy Constructor
		Fixed &operator=(const Fixed &other);	// Copy assignment operator overload
		~Fixed(void);							// Default Destructor
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
