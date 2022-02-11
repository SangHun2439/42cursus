/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:20:41 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/11 15:23:11 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x;
		Fixed const y;
	public:
		Point();
		Point(const Point &src);
		Point(const float x, const float y);
		Point	&operator=(const Point &src);
		Fixed	getX() const;
		Fixed	getY() const;
		~Point();
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
