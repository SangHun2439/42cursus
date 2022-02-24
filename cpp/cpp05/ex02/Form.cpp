/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:44:53 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/24 16:11:17 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():name("unknown"), grade_sign(150), grade_exec(150), is_sign(false) {}

Form::Form(const std::string& name, int grade_sign, int grade_exec):name(name), grade_sign(grade_sign), grade_exec(grade_exec), is_sign(false)
{
	if (grade_exec < 1 || grade_sign < 1)
		throw GradeTooHighException();
	if (grade_exec > 150 || grade_sign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src):name(src.name), grade_sign(src.grade_sign), grade_exec(src.grade_exec), is_sign(src.is_sign)
{
	if (src.grade_exec < 1 || src.grade_sign < 1)
		throw GradeTooHighException();
	if (src.grade_exec > 150 || src.grade_sign > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form&	Form::operator=(Form& src)
{
	(void)src;
	return (*this);
}

const std::string&	Form::getName() const
{
	return (this->name);
}

int	Form::getGrade_sign() const
{
	return (this->grade_sign);
}

int	Form::getGrade_exec() const
{
	return (this->grade_exec);
}

bool	Form::getIs_sign() const
{
	return (this->is_sign);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->grade_sign)
		throw Form::GradeTooLowException();
	is_sign = true;
}

void	Form::exec_check(Bureaucrat const & executor) const
{
	if (!is_sign)
		throw Form::NotSigned();
	if (executor.getGrade() > this->grade_exec)
		throw Form::GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("form except: grade is too high, over 1");
}


const char*	Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("form except: grade is too low, over 150");
}

const char*	Form::NotSigned::what() const _NOEXCEPT
{
	return ("form except: form is not signed");
}


std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << "<" << form.getName() << ">";
	if (form.getIs_sign())
		os << "is signed ";
	else if (!form.getIs_sign())
		os << "is not signed ";
	os << "has (" << form.getGrade_sign() << ") sign grade, (" << form.getGrade_exec() << ") exec grade";
	return (os);
}
