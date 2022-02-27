/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:27:55 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 21:54:15 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoubleConvert.hpp"

DoubleConvert::DoubleConvert():val(0), overflow(false) {}

DoubleConvert::DoubleConvert(const std::string& literal):Convert(literal, static_cast<const std::string>("double")), val(0), overflow(false) {}

DoubleConvert::DoubleConvert(const DoubleConvert& src):Convert(src.getLiteral(), src.getType()), val(src.val), overflow(src.overflow) {}

DoubleConvert::~DoubleConvert() {}

DoubleConvert&	DoubleConvert::operator=(const DoubleConvert& src)
{
	if (this == &src)
		return (*this);
	literal = src.literal;
	val = src.val;
	overflow = src.overflow;
	return (*this);
}

void	DoubleConvert::doConvert()
{
	if (literal == "nan")
	{
		val = std::numeric_limits<double>::quiet_NaN();
		return ;
	}
	if (literal == "-inf")
	{
		val = -std::numeric_limits<double>::infinity();
		return ;
	}
	if (literal == "+inf")
	{
		val = std::numeric_limits<double>::infinity();
		return ;
	}
	try
	{
		val = std::stod(literal);
	}
	catch (std::out_of_range& e)
	{
		overflow = true;
	}
}

char	DoubleConvert::toChar()
{
	if (overflow || val > static_cast<double>(CHAR_MAX) || val < static_cast<double>(CHAR_MIN))
		throw (Convert::Impossible());
	if (std::isnan(val))
		throw (Convert::Impossible());
	if (std::isinf(val))
		throw (Convert::Impossible());
	if (!static_cast<bool>(std::isprint(static_cast<int>(static_cast<char>(val)))))
		throw (Convert::NonDisplayable());
	return (static_cast<char>(val));
}

int	DoubleConvert::toInt()
{
	if (overflow || val > static_cast<double>(INT_MAX) || val < static_cast<double>(INT_MIN))
		throw (Convert::Impossible());
	if (std::isnan(val))
		throw (Convert::Impossible());
	if (std::isinf(val))
		throw (Convert::Impossible());
	return (static_cast<int>(val));
}

float	DoubleConvert::toFloat()
{
	double	abs_val;

	if (val == 0.0)
		return (static_cast<float>(val));
	if (std::isnan(val) || std::isinf(val))
		return (static_cast<float>(val));
	abs_val = val;
	if (val < 0.0)
		abs_val = - val;
	if (overflow || abs_val > static_cast<double>(__FLT_MAX__) || abs_val < static_cast<double>(__FLT_MIN__))
		throw (Convert::Impossible());
	return (static_cast<float>(val));
}

double	DoubleConvert::toDouble()
{
	if (overflow)
		throw (Convert::Impossible());
	return (static_cast<double>(val));
}
