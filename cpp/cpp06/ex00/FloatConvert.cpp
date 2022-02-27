/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatConvert.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:27:55 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 22:22:32 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FloatConvert.hpp"

FloatConvert::FloatConvert():val(0), overflow(false) {}

FloatConvert::FloatConvert(const std::string& literal):Convert(literal, static_cast<const std::string>("float")), val(0), overflow(false) {}

FloatConvert::FloatConvert(const FloatConvert& src):Convert(src.getLiteral(), src.getType()), val(src.val), overflow(src.overflow) {}

FloatConvert::~FloatConvert() {}

FloatConvert&	FloatConvert::operator=(const FloatConvert& src)
{
	if (this == &src)
		return (*this);
	literal = src.literal;
	val = src.val;
	overflow = src.overflow;
	return (*this);
}

void	FloatConvert::doConvert()
{
	if (literal == "nanf")
	{
		val = std::numeric_limits<float>::quiet_NaN();
		return ;
	}
	if (literal == "-inff")
	{
		val = -std::numeric_limits<float>::infinity();
		return ;
	}
	if (literal == "+inff")
	{
		val = std::numeric_limits<float>::infinity();
		return ;
	}
	try
	{
		val = std::stof(literal);
	}
	catch (std::out_of_range& e)
	{
		overflow = true;
	}
}

char	FloatConvert::toChar()
{
	if (overflow || val > static_cast<float>(CHAR_MAX) || val < static_cast<float>(CHAR_MIN))
		throw (Convert::Impossible());
	if (std::isnan(val))
		throw (Convert::Impossible());
	if (std::isinf(val))
		throw (Convert::Impossible());
	if (!static_cast<bool>(std::isprint(static_cast<int>(static_cast<char>(val)))))
		throw (Convert::NonDisplayable());
	return (static_cast<char>(val));
}

int	FloatConvert::toInt()
{
	if (overflow || static_cast<double>(val) > static_cast<double>(INT_MAX) || static_cast<double>(val) < static_cast<double>(INT_MIN))
		throw (Convert::Impossible());
	if (std::isnan(val))
		throw (Convert::Impossible());
	if (std::isinf(val))
		throw (Convert::Impossible());
	return (static_cast<int>(val));
}

float	FloatConvert::toFloat()
{
	if (overflow)
		throw (Convert::Impossible());
	return (static_cast<float>(val));
}

double	FloatConvert::toDouble()
{
	if (overflow)
		throw (Convert::Impossible());
	return (static_cast<double>(val));
}
