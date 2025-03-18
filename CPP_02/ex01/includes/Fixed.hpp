#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {
	
	private:
		int					_rawValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);							// default Constructor
		Fixed(const int value);					// parameterized Constructor
		Fixed(const float value);				// parameterized Constructor
		Fixed(const Fixed& other);				// copy Constructor
		Fixed &operator=(const Fixed &other);	// copy assignment operator overload
		~Fixed(void);							// default Destructor
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;			// converts the fixed-point value to a floating-point value
		int		toInt(void) const;				// converts the fixed-point value to an integer value
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // overload of the insertion («) operator

#endif

