/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:30:08 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/24 14:39:30 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat a("brad", 5);
	Form	form1("form1", 3, 1);
	Form	form2("form2", 10, 15);
	try
	{
		Form	form3("form3", 151, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form	form4("form4", -1, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	a.signForm(form1);
	a.signForm(form2);
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	return (0);
}
