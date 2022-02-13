/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:34:23 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 15:49:56 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap():ClapTrap()
{
	std::cout << "FragTrap " << "default constructor called <" << this->name << "> is created"<< std::endl;
	this->HitPoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap " << "string constructor called <" << this->name << "> is created"<< std::endl;
	this->HitPoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << "FragTrap " << "copy constructor called <" << this->name << "> is created"<< std::endl;
	this->name = src.name;
	this->HitPoints = src.HitPoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap" << " destructor called <" << this->name << "> is removed" <<std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	this->name = src.name;
	this->HitPoints = src.HitPoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	std::cout << "FragTrap" << " assignation operator called" <<std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap <" + this->name + "> is called positive high fives request!" << std::endl;
}

void	FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap <" + this->name + "> attack <" + target + ">, causing <";
	std::cout << this->Attack_damage << "> points of damage!" << std::endl;
	this->HitPoints--;
}
