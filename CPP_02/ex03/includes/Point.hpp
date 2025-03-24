/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:25:03 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 09:25:47 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {

	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point(void);

		bool	operator==(const Point &other) const;
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
