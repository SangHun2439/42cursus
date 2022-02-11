/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:34:00 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/11 22:28:57 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap " << "constructor called <" << this->getName() << "> is created"<< std::endl;
	this->setHitPoints(100);
	this->setEnergy_points(50);
	this->setAttack_damage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap" << " destructor called <" << this->getName() << "> is removed" <<std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap <" + this->getName() + "> attack <" + target + ">, causing <";
	std::cout << this->getAttack_damage() << "> points of damage!" << std::endl;
	this->setHitPoints(this->getHitPoints() - 1);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap <" + this->getName() + "> have enterred in Gate keeper mode!" << std::endl;
}
