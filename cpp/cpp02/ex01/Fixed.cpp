/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:49:49 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/09 23:45:51 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed():val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &origin)
{
	std::cout << "Copy constructor called" << std::endl;
	val = origin.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int to_convert)
{
	std::cout << "Int constructor called" << std::endl;
	val = (to_convert << b_fract);
}

Fixed::Fixed(const float to_convert)
{
	std::cout << "Float constructor called" << std::endl;
	val = roundf( to_convert * (1 << b_fract));
}

Fixed &Fixed::operator=(const Fixed &origin)
{
	std::cout << "Assignation operator called" << std::endl;
	val = origin.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return val;
}

void	Fixed::setRawBits( int const raw )
{
	val = raw;
}

int	Fixed::toInt( void ) const
{
	return (val >> b_fract);
}

float	Fixed::toFloat( void ) const
{
	return ((float) val / (1 << b_fract));
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	os << (fixed.toFloat());
	return (os);
}
