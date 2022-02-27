/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConvert.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:27:55 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 15:15:25 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IntConvert.hpp"

IntConvert::IntConvert():val(0), overflow(false) {}

IntConvert::IntConvert(const std::string& literal):Convert(literal, static_cast<const std::string>("int")), val(0), overflow(false) {}

IntConvert::IntConvert(const IntConvert& src):Convert(src.getLiteral(), src.getType()), val(src.val), overflow(src.overflow) {}

IntConvert::~IntConvert() {}

IntConvert&	IntConvert::operator=(const IntConvert& src)
{
	if (this == &src)
		return (*this);
	literal = src.literal;
	val = src.val;
	overflow = src.overflow;
	return (*this);
}

void	IntConvert::doConvert()
{
	try
	{
		val = std::stoi(literal);
	}
	catch (std::out_of_range& e)
	{
		overflow = true;
	}
}

char	IntConvert::toChar()
{
	if (overflow || val > CHAR_MAX || val < CHAR_MIN)
		throw (Convert::Impossible());
	if (!std::isprint(static_cast<int>(static_cast<char>(val))))
		throw (Convert::NonDisplayable());
	return (static_cast<char>(val));
}

int	IntConvert::toInt()
{
	if (overflow)
		throw (Convert::Impossible());
	return (static_cast<int>(val));
}

float	IntConvert::toFloat()
{
	if (overflow)
		throw (Convert::Impossible());
	return (static_cast<float>(val));
}

double	IntConvert::toDouble()
{
	if (overflow)
		throw (Convert::Impossible());
	return (static_cast<double>(val));
}
