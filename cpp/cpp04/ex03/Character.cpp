/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:51:43 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/23 16:17:59 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character():name("unknown")
{
	for (int i = 0; i < INVENTORY_NUM; i++)
		this->inventory[i] = 0;
}

Character::Character(const std::string &name):name(name)
{
	for (int i = 0; i < INVENTORY_NUM; i++)
		this->inventory[i] = 0;
}

Character::Character(const Character &src):name(src.name)
{
	for (int i = 0; i < INVENTORY_NUM; i++)
	{
		if (src.inventory[i])
			inventory[i] = src.inventory[i]->clone();
		else
			this->inventory[i] = 0;
	}
}

Character	&Character::operator=(const Character &src)
{
	this->name = src.name;
	for (int i = 0; i < INVENTORY_NUM; i++)
	{
		if (inventory[i])
			delete inventory[i];
		if (src.inventory[i])
			inventory[i] = src.inventory[i]->clone();
		else
			this->inventory[i] = 0;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < INVENTORY_NUM; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

std::string const	&Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	int	i;

	i = 0;
	while (i < INVENTORY_NUM && inventory[i])
		i++;
	if (i != INVENTORY_NUM)
		inventory[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx >= INVENTORY_NUM || idx < 0)
		return ;
	if (inventory[idx])
		inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= INVENTORY_NUM || idx < 0)
		return ;
	if (inventory[idx])
		inventory[idx]->use(target);
}
