/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:24:36 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 09:24:37 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other) {
	(void) other;
	return (*this);
}

Point::~Point(void) {}

bool Point::operator==(const Point &other) const {
	return (_x == other._x && _y == other._y);
}

Fixed Point::getX(void) const	{ return (this->_x); }
Fixed Point::getY(void) const	{ return (this->_y); }
