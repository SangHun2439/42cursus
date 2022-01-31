/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:06:08 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/29 23:04:54 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

void	HumanA::attack( void )
{
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}

HumanA::HumanA( std::string name, Weapon &weapon ):weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA()
{
}
