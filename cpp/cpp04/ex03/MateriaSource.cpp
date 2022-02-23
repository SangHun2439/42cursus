/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:44:44 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/23 16:57:21 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MATERIAL_NUM; i++)
		this->materials[i] = 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MATERIAL_NUM; i++)
	{
		if (materials[i])
		{
			delete materials[i];
			materials[i] = 0;
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < MATERIAL_NUM; i++)
	{
		if (src.materials[i])
			this->materials[i] = src.materials[i]->clone();
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &src)
{
	for (int i = 0; i < MATERIAL_NUM; i++)
	{
		if (materials[i])
			delete materials[i];
		if (src.materials[i])
			this->materials[i] = src.materials[i]->clone();
		else
			materials[i] = 0;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	i = 0;
	while (i < MATERIAL_NUM && materials[i])
		i++;
	if (i != MATERIAL_NUM)
		materials[i] = m;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	int	i;

	i = 0;
	while (i < MATERIAL_NUM)
	{
		if (materials[i] && materials[i]->getType() == type)
			return (materials[i]->clone());
		i++;
	}
	return (0);
}
