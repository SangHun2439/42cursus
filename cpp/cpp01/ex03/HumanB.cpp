/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:17:09 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/29 23:38:58 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

void	HumanB::attack( void )
{
	std::cout << name << " attacks with his " << (*weapon).getType() << std::endl;
}

HumanB::HumanB( std::string name )
{
	this->name = name;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}
