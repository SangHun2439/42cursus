/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:27:56 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/15 22:37:11 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat():Animal("Cat")
{
	std::cout << "Cat default constructor is called " << this->type << " is created" << std::endl;
}

Cat::Cat(const Cat &src):Animal(src.type)
{
	std::cout << "Cat copy constructor is called " << this->type << " is created" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called " << this->type << " is removed" << std::endl;
}

Cat	&Cat::operator=(const Cat &src)
{
	this->type = src.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat sound ~~~~ !" << std::endl;
}
