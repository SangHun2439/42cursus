/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:57:07 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/22 17:09:28 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const AMateria &src):type(src.type)
{
}

AMateria::AMateria(std::string const &type):type(type)
{
}

AMateria::~AMateria()
{
}

AMateria	&AMateria::operator=(const AMateria &src)
{
	this->type = src.type;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}
