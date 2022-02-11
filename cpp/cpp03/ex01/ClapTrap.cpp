/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:03:54 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/11 22:19:37 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name):name(name), HitPoints(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap " << "constructor called <" << this->name << "> is created"<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap" << " destructor called <" << this->name << "> is removed" <<std::endl;
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap <" + this->name + "> attack <" + target + ">, causing <";
	std::cout << this->Attack_damage << "> points of damage!" << std::endl;
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

void	ClapTrap::setAttack_damage( int n )
{
	this->Attack_damage = n;
}

void	ClapTrap::setEnergy_points( int n )
{
	this->Energy_points = n;
}

void	ClapTrap::setHitPoints( int n )
{
	this->HitPoints = n;
}

std::string	ClapTrap::getName() const
{
	return (this->name);
}

int		ClapTrap::getHitPoints() const
{
	return (this->HitPoints);
}

int		ClapTrap::getEnergy_points() const
{
	return (this->Energy_points);
}

int		ClapTrap::getAttack_damage() const
{
	return (this->Attack_damage);
}
