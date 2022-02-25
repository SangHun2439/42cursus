/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:30:08 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/25 14:00:01 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat a("brad", 5);
	Intern someRandomIntern;
	Form* rrf;
	try
	{
		rrf = someRandomIntern.makeForm("what", "Bender");
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "jeson");
	a.executeForm(*rrf);
	delete rrf;

	return (0);
}
