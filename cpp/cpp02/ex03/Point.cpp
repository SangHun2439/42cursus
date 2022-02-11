/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:20:32 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/11 15:19:55 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(Fixed(0)), y(Fixed(0))
{
}

Point::Point(const Point &src):x(src.x), y(src.y)
{
}

Point::Point(const float x, const float y):x(Fixed(x)), y(Fixed(y))
{
}

Point	&Point::operator=(const Point &src)
{
	(void)src;
	return (*this);
}

Point::~Point()
{
}

Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}
