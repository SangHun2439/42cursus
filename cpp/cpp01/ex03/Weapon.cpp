/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:22:51 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/29 22:25:07 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	&Weapon::getType( void )
{
	return (type);
}

void	Weapon::setType( std::string type)
{
	this->type = type;
}

Weapon::Weapon( std::string type )
{
	this->type = type;
}
