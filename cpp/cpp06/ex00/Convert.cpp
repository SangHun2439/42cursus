/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:03:52 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 16:18:06 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert():literal(static_cast<std::string>("none")), type(static_cast<std::string>("none")) {}

Convert::Convert(const std::string& literal, const std::string& type):literal(literal), type(type) {}

Convert::Convert(const Convert& src):literal(src.literal), type(src.type) {}

Convert::~Convert() {}

Convert&	Convert::operator=(const Convert& src)
{
	if (this == &src)
		return (*this);
	literal = src.literal;
	return (*this);
}

const std::string&	Convert::getLiteral() const
{
	return (literal);
}

const std::string&	Convert::getType() const
{
	return (type);
}

void	Convert::setLiteral(const std::string& literal)
{
	this->literal = literal;
}

const char*	Convert::Impossible::what() const _NOEXCEPT
{
	return ("impossible");
}

const char*	Convert::NonDisplayable::what() const _NOEXCEPT
{
	return ("Non displayable");
}

std::ostream&	operator<<(std::ostream& os, Convert& convert)
{
	std::cout << "char: ";
	try
	{
		std::cout << convert.toChar() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "int: ";
	try
	{
		std::cout << convert.toInt() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: ";
	try
	{
		std::cout << convert.toFloat() << "f\n";
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "double: ";
	try
	{
		std::cout << convert.toDouble();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	return (os);
}
