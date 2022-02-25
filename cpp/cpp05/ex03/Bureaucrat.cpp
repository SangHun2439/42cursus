/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:45:40 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/24 17:23:55 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("unknown"), grade(150) {}

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
	(void)src;
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

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << "<" << name << "> cannot sign <" << form.getName() << "> because grade is too low" << std::endl;
		return ;
	}
	std::cout << "<" << name << "> signs <" << form.getName() << ">" << std::endl;
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << "<" << name << "> cannot execute <" << form.getName() << "> because grade is too low" << std::endl;
		return ;
	}
	catch (Form::NotSigned& e)
	{
		std::cout << "<" << name << "> cannot execute <" << form.getName() << "> because it is not signed" << std::endl;
		return ;
	}
	std::cout << "<" << name << "> executes <" << form.getName() << ">" << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Bureaucrat except: grade is too high, over 1");
}

const char*	Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Bureaucrat except: grade is too low, over 150");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << "<" << bureaucrat.getName() << ">, bureaucrat grade <" << bureaucrat.getGrade() << ">.";
	return (os);
}
