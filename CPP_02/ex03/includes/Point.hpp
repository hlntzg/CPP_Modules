#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {

	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(const float x, const float y);
//		Point(const Fixed x, const Fixed y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point(void);

		bool	operator==(const Point &other) const;
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
