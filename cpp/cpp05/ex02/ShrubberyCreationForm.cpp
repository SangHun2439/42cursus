/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:51:23 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/24 16:14:59 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm():Form("ShrubberyCreationForm", 145, 137), target("unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):Form("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):Form(src), target(src.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	target = src.target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	ofs;

	exec_check(executor);
	ofs.open("<" + target + ">" + "_shrubbery");
	ofs << "       _-_\n";
	ofs << "    /~~   ~~\\\n";
	ofs << " /~~         ~~\\\n";
	ofs << "{               }\n";
	ofs << " \\  _-     -_  /\n";
	ofs << "   ~  \\\\ //  ~\n";
	ofs << "_- -   | | _- _\n";
	ofs << "  _ -  | |   -_\n";
	ofs << "      // \\\\\n";
	ofs << std::endl;
	ofs.close();
}
