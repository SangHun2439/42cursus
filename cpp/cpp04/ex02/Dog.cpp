/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:25:39 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/21 17:52:55 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog():Animal("Dog")
{
	std::cout << "Dog default constructor is called " << this->type << " is created" << std::endl;
	this->brain = new Brain;
}

Dog::Dog(const Dog &src):Animal(src.type)
{
	std::cout << "Dog copy constructor is called " << this->type << " is created" << std::endl;
	this->brain = new Brain(*(src.brain));
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called " << this->type << " is removed" << std::endl;
	delete this->brain;
}

Dog	&Dog::operator=(const Dog &src)
{
	this->type = src.type;
	*(this->brain) = *(src.brain);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog sound ~~~~ !" << std::endl;
}

void	Dog::setBrain(std::string *ideas, int size)
{
	this->brain->setIdeas(ideas, size);
}

void	Dog::printIdeas() const
{
	this->brain->printIdeas();
}
