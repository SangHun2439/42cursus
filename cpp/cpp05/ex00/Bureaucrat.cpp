/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:45:40 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/24 11:34:52 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("unknown"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.name), grade(src.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat& src)
{
	if (this == &src)
		return (*this);
	grade = src.grade;
	return (*this);
}

const std::string&	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incregrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decregrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("grade is too high, over 1");
}

const char*	Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("grade is too low, over 150");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << "<" << bureaucrat.getName() << ">, bureaucrat grade <" << bureaucrat.getGrade() << ">.";
	return (os);
}
