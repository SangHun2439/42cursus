/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:49:49 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/09 23:55:31 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed():val(0)
{
}

Fixed::Fixed(const Fixed &origin)
{
	val = origin.getRawBits();
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int to_convert)
{
	val = (to_convert << b_fract);
}

Fixed::Fixed(const float to_convert)
{
	val = roundf( to_convert * (1 << b_fract));
}

Fixed	&Fixed::operator=(const Fixed &origin)
{
	val = origin.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &a)
{
	return (val > a.val);
}

bool	Fixed::operator<(const Fixed &a)
{
	return (val < a.val);
}

bool	Fixed::operator>=(const Fixed &a)
{
	return (val >= a.val);
}

bool	Fixed::operator<=(const Fixed &a)
{
	return (val <= a.val);
}

bool	Fixed::operator==(const Fixed &a)
{
	return (val == a.val);
}

bool	Fixed::operator!=(const Fixed &a)
{
	return (val != a.val);
}

Fixed	Fixed::operator+(const Fixed &a)
{
	return (Fixed(this->toFloat() + a.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &a)
{
	return (Fixed(this->toFloat() - a.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &a)
{
	return (Fixed( this->toFloat() * a.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &a)
{
	return (Fixed( this->toFloat() / a.toFloat()));
}

Fixed	&Fixed::operator++()
{
	val++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	++*this;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	val--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	--*this;
	return (*this);
}

std::ostream&	operator<<(std::ostream &os, const Fixed &fixed)
{
	os << (fixed.toFloat());
	return (os);
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

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	else
		return (a);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	else
		return (a);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	else
		return (a);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	else
		return (a);
}
