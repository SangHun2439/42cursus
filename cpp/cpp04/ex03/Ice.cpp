/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:16:53 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/22 17:06:35 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice():AMateria("ice")
{
}

Ice::Ice(const Ice &src):AMateria(src.type)
{
}

Ice	&Ice::operator=(const Ice &src)
{
	(void)src;
	return (*this);
}

Ice::~Ice()
{
}

Ice	*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
