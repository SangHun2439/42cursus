/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:06:04 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 16:41:15 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap():ClapTrap("unknown_clap_name"), name("unknown")
{
	std::cout << "DiamondTrap " << "default constructor called <" << this->name << "> is created"<< std::endl;
	this->HitPoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), name(name)
{
	std::cout << "DiamondTrap " << "string constructor called <" << this->name << "> is created"<< std::endl;
	this->HitPoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	std::cout << "DiamondTrap " << "copy constructor called <" << this->name << "> is created"<< std::endl;
	this->name = src.name;
	this->ClapTrap::name = src.ClapTrap::name;
	this->HitPoints = src.HitPoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap" << " destructor called <" << this->name << "> is removed" <<std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
	this->name = src.name;
	this->ClapTrap::name = src.ClapTrap::name;
	this->HitPoints = src.HitPoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	std::cout << "DiamondTrap" << " assignation operator called" <<std::endl;
	return (*this);
}

void	DiamondTrap::attack(const std::string &target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "my name : " + this->name + " | clapTram name : " + this->ClapTrap::name << std::endl;
}
