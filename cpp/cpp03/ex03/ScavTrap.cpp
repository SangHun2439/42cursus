/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:34:00 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 15:45:36 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap():ClapTrap()
{
	std::cout << "ScavTrap " << "default constructor called <" << this->name << "> is created"<< std::endl;
	this->HitPoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap " << "string constructor called <" << this->name << "> is created"<< std::endl;
	this->HitPoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "ScavTrap " << "copy constructor called <" << this->name << "> is created"<< std::endl;
	this->name = src.name;
	this->HitPoints = src.HitPoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap" << " destructor called <" << this->name << "> is removed" <<std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	this->name = src.name;
	this->HitPoints = src.HitPoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	std::cout << "ScavTrap" << " assignation operator called" <<std::endl;
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap <" + this->name + "> attack <" + target + ">, causing <";
	std::cout << this->Attack_damage << "> points of damage!" << std::endl;
	this->HitPoints--;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap <" + this->name + "> have enterred in Gate keeper mode!" << std::endl;
}
