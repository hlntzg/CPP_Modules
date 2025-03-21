#include "Point.hpp"

static Fixed	crossProduct(Point const point, Point const p1, Point const p2) {
	
	return (((point.getX() - p2.getX()) * (p1.getY() - p2.getY())) - ((p1.getX() - p2.getX()) * (point.getY() - p2.getY())));
}

// bsp (Binary Space Partitioning) function, which checks whether a given point lies inside a triangle.
bool	bsp(Point const a, Point const b, Point const c, Point const point) {

	Fixed	position1 = crossProduct(point, a, b);
	Fixed	position2 = crossProduct(point, b, c);
	Fixed	position3 = crossProduct(point, c, a);

	if ((position1 > 0 && position2 > 0 && position3 > 0) || (position1 < 0 && position2 < 0 && position3 < 0))
		return (true);
	return (false);
}
