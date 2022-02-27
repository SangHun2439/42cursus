/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Detect.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:18:59 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 21:53:03 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Detect.hpp"

Detect::Detect()
{
	literal = static_cast<std::string>("none");
}

Detect::Detect(const char* literal)
{
	this->literal = static_cast<std::string>(literal);
}

Detect::Detect(const Detect& src):literal(src.literal) {}

Detect::~Detect() {}

Detect&	Detect::operator=(const Detect& src)
{
	if (this == &src)
		return (*this);
	literal = src.literal;
	return (*this);
}

bool	Detect::isChar() const
{
	if (literal.size() == static_cast<size_t>(1) && !static_cast<bool>(std::isdigit(static_cast<int>(literal.at(static_cast<size_t>(0))))))
		return (true);
	return (false);
}

bool	Detect::isInt() const
{
	int	i;

	i = 0;
	if (literal.at(static_cast<size_t>(0)) == '-')
		i++;
	while (i < static_cast<int>(literal.size()))
	{
		if (!static_cast<bool>(std::isdigit(static_cast<int>(literal.at(static_cast<size_t>(i))))))
			return (false);
		i++;
	}
	return (true);
}

bool	Detect::isFloat() const
{
	size_t	i;
	bool	dot;

	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	if (!(literal.at(literal.size() - static_cast<size_t>(1)) == 'f'))
		return (false);
	i = 0;
	dot = false;
	if (literal.at(static_cast<size_t>(0)) == '-')
		i++;
	while (i < static_cast<int>(literal.size()) - static_cast<size_t>(1))
	{
		if (!dot && literal.at(static_cast<size_t>(i)) == '.')
		{
			dot = true;
			i++;
			continue;
		}
		if (!static_cast<bool>(std::isdigit(static_cast<int>(literal.at(static_cast<size_t>(i))))))
			return (false);
		i++;
	}
	return (true);
}

bool	Detect::isDouble() const
{
	int		i;
	bool	dot;

	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	i = 0;
	dot = false;
	if (literal.at(static_cast<size_t>(0)) == '-')
		i++;
	while (i < static_cast<int>(literal.size()))
	{
		if (!dot && literal.at(static_cast<size_t>(i)) == '.')
		{
			dot = true;
			i++;
			continue;
		}
		if (!static_cast<bool>(std::isdigit(static_cast<int>(literal.at(static_cast<size_t>(i))))))
			return (false);
		i++;
	}
	return (true);
}

Convert*	Detect::getRightConvert()
{
	if (isChar())
		return (static_cast<Convert*>(new CharConvert(literal)));
	if (isInt())
		return (static_cast<Convert*>(new IntConvert(literal)));
	if (isFloat())
		return (static_cast<Convert*>(new FloatConvert(literal)));
	if (isDouble())
		return (static_cast<Convert*>(new DoubleConvert(literal)));
	throw (Detect::NotScalarType());
}

const char*	Detect::NotScalarType::what() const _NOEXCEPT
{
	return ("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible");
}
