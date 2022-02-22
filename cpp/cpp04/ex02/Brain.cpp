/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:44:06 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/21 17:48:17 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain():size(0)
{
	std::cout << "Brain constructor is called "<< std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called "<< std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor is called "<< std::endl;

	for (int i = 0; i < src.size; i++)
		this->ideas[i] = src.ideas[i];
	this->size = src.size;
}

Brain	&Brain::operator=(const Brain &src)
{
	for (int i = 0; i < src.size; i++)
		this->ideas[i] = src.ideas[i];
	this->size = src.size;
	return (*this);
}

void	Brain::setIdeas(std::string *ideas, int size)
{
	if (size > IDEAS_NUM)
		return ;
	for (int i = 0; i < size; i++)
		this->ideas[i] = ideas[i];
	this->size = size;
}

void	Brain::printIdeas() const
{
	for (int i = 0; i < this->size; i++)
		std::cout << this->ideas[i] << " ";
	std::cout << std::endl;
}

