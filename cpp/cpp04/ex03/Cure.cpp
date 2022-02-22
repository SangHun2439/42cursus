/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:14:00 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/22 17:06:21 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure():AMateria("cure")
{
}

Cure::Cure(const Cure &src):AMateria(src.type)
{
}

Cure	&Cure::operator=(const Cure &src)
{
	(void)src;
	return (*this);
}

Cure::~Cure()
{
}

Cure	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
