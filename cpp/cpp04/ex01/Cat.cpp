/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:27:56 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/21 17:52:40 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat():Animal("Cat")
{
	std::cout << "Cat default constructor is called " << this->type << " is created" << std::endl;
	this->brain = new Brain;
}

Cat::Cat(const Cat &src):Animal(src.type)
{
	std::cout << "Cat copy constructor is called " << this->type << " is created" << std::endl;
	this->brain = new Brain(*(src.brain));
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called " << this->type << " is removed" << std::endl;
	delete this->brain;
}

Cat	&Cat::operator=(const Cat &src)
{
	this->type = src.type;
	*(this->brain) = *(src.brain);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat sound ~~~~ !" << std::endl;
}

void	Cat::setBrain(std::string *ideas, int size)
{
	this->brain->setIdeas(ideas, size);
}

void	Cat::printIdeas() const
{
	this->brain->printIdeas();
}
