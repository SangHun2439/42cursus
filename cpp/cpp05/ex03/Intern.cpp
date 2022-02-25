/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:38:36 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/25 14:10:27 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src)
{
	(void)src;
}

Intern::~Intern() {}

Intern&	Intern::operator=(const Intern& src)
{
	(void)src;
	return (*this);
}

Form*	Intern::makeSform(const std::string& name, const std::string& target)
{
	if (name != "ShrubberyCreationForm")
		throw (Intern::NotExistForm());
	return (new ShrubberyCreationForm(target));
}

Form*	Intern::makePform(const std::string& name, const std::string& target)
{
	if (name != "PresidentialPardonForm")
		throw (Intern::NotExistForm());
	return (new PresidentialPardonForm(target));
}

Form*	Intern::makeRform(const std::string& name, const std::string& target)
{
	if (name != "RobotomyRequestForm")
		throw (Intern::NotExistForm());
	return (new RobotomyRequestForm(target));
}

Form*	Intern::makeForm(const std::string& name, const std::string& target)
{
	try
	{
		return (this->makeSform(name, target));
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		return (this->makePform(name, target));
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		return (this->makeRform(name, target));
	}
	catch(const std::exception& e)
	{
	}
	throw (Intern::NotExistForm());
}

const char*	Intern::NotExistForm::what() const _NOEXCEPT
{
	return ("Intern: not exist that form");
}
