/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:30:08 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/24 17:26:35 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{

	Form*	form1 = new ShrubberyCreationForm("home");
	Form*	form2 = new PresidentialPardonForm("sangjeon");
	Form*	form3 = new RobotomyRequestForm("jeson");

	Bureaucrat a("brad", 5);
	Bureaucrat b("joy", 150);

	b.signForm(*form1);
	b.executeForm(*form1);
	b.signForm(*form2);
	b.executeForm(*form2);
	b.signForm(*form3);
	b.executeForm(*form3);

	a.signForm(*form1);
	a.executeForm(*form1);
	a.signForm(*form2);
	a.executeForm(*form2);
	a.signForm(*form3);
	a.executeForm(*form3);

	std::cout << *form1 << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << *form3 << std::endl;

	delete form1;
	delete form2;
	delete form3;

	return (0);
}
