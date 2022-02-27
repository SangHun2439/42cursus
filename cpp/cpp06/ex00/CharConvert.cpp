/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConvert.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:27:55 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 15:10:49 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CharConvert.hpp"

CharConvert::CharConvert():val(0) {}

CharConvert::CharConvert(const std::string& literal):Convert(literal, static_cast<const std::string>("char")), val(0) {}

CharConvert::CharConvert(const CharConvert& src):Convert(src.getLiteral(), src.getType()), val(src.val) {}

CharConvert::~CharConvert() {}

CharConvert&	CharConvert::operator=(const CharConvert& src)
{
	if (this == &src)
		return (*this);
	literal = src.literal;
	val = src.val;
	return (*this);
}

void	CharConvert::doConvert()
{
	val = static_cast<char>(literal.at(static_cast<size_t>(0)));
}

char	CharConvert::toChar()
{
	if (!std::isprint(static_cast<int>(static_cast<char>(val))))
		throw (Convert::NonDisplayable());
	return (static_cast<char>(val));
}

int	CharConvert::toInt()
{
	return (static_cast<int>(val));
}

float	CharConvert::toFloat()
{
	return (static_cast<float>(val));
}

double	CharConvert::toDouble()
{
	return (static_cast<double>(val));
}
