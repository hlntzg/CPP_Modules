#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed {
	
	private:
		int					_rawValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);							// default Constructor
		Fixed(const Fixed& other);				// copy Constructor
		Fixed &operator=(const Fixed &other);	// copy assignment operator overload
		~Fixed(void);							// default Destructor
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
