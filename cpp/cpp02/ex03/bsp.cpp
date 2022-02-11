/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:21:08 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/11 17:41:49 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	is_in(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	x_d;
	Fixed	y_d;
	Fixed	bias;
	bool	up;
	bool	test;

	x_d = a.getX() - b.getX();
	y_d = a.getY() - b.getY();
	bias = (x_d * a.getY()) - (y_d * a.getX());
	up = (x_d * c.getX()) - (y_d * c.getX()) - bias > Fixed(0);
	test = (x_d * point.getY()) - (y_d * point.getX()) - bias > Fixed(0);
	if (up == test)
		return (true);
	else
		return (false);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	if (is_in(a, b, c, point) && is_in(b, c, a, point) && is_in(c, b, a, point))
		return (true);
	else
		return (false);
}
