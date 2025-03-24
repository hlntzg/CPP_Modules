/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:24:46 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 13:41:38 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/** 
 * Computes the cross product of two vectors (p1 - p2) and (point - p2).
 * The cross product helps determine the relative position of `point` with respect to the directed line `p1 -> p2`.
 * 
 * @param point The point to check.
 * @param p1 First point of the line (vertice 1).
 * @param p2 Second point of the line (vertice 2).
 * @return (positive or negative) Fixed value representing the cross product result.
 */
static Fixed	crossProduct(Point const point, Point const p1, Point const p2)
{	
	return (((point.getX() - p2.getX()) * (p1.getY() - p2.getY())) -
				((p1.getX() - p2.getX()) * (point.getY() - p2.getY())));
}

/**
 * Determines whetheir a given point lies inside a triangle using the Binary Space Partitioning (BSP) technique.
 *
 * Calculates the cross product of the given point with respect to the three edges of the triangle.
 * If all cross products are all positive or all negative, the point is inside the triangle.
 *
 * @param a, b, c Vertices of the triangle.
 * @param point The point to check.
 * @return True if the point is inside the triangle, otherwise false.
 */
bool	bsp(Point const a, Point const b, Point const c, Point const point) {

	Fixed	position1 = crossProduct(point, a, b);
	Fixed	position2 = crossProduct(point, b, c);
	Fixed	position3 = crossProduct(point, c, a);

	if ((position1 > 0 && position2 > 0 && position3 > 0) || (position1 < 0 && position2 < 0 && position3 < 0))
		return (true);
	return (false);
}
