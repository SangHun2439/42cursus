/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:52:21 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/25 10:35:35 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():Form("RobotomyRequestForm", 72, 45), target("unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):Form(src), target(src.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	target = src.target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	exec_check(executor);
	std::cout << "drrrrrrrrrrr....";
	time_t	now;
	time(&now);
	if (now % 2)
		std::cout << "<" << target << "> has been robotomized successfully 50% of the time" << std::endl;
	else
		std::cout << "<" << target << "> robotimization is failed" << std::endl;

}
