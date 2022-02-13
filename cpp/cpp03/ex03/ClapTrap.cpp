/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:03:54 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 15:40:37 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap():name("unknown"), HitPoints(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap " << "default constructor called <" << this->name << "> is created"<< std::endl;
}

ClapTrap::ClapTrap(std::string name):name(name), HitPoints(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap " << "string constructor called <" << this->name << "> is created"<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src):name(src.name), HitPoints(src.HitPoints), Energy_points(src.Energy_points), Attack_damage(src.Attack_damage)
{
	std::cout << "ClapTrap " << "copy constructor called <" << this->name << "> is created"<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap" << " destructor called <" << this->name << "> is removed" <<std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	this->name = src.name;
	this->HitPoints = src.HitPoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	std::cout << "ClapTrap" << " assignation operator called" <<std::endl;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap <" + this->name + "> attack <" + target + ">, causing (";
	std::cout << this->Attack_damage << ") points of damage!" << std::endl;
	this->HitPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap <" + this->name + "> takes (";
	std::cout << amount << ") of damage" << std::endl;
	this->Energy_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap <" + this->name + "> is repaired, (";
	std::cout << amount << ") of energy points is restored" << std::endl;
	this->Energy_points += amount;
}
