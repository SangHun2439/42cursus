/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:18:08 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/15 23:01:31 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal():type("UnknownWrongAnimal")
{
	std::cout << "WrongAnimal default constructor is called " << this->type << " is created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type):type(type)
{
	std::cout << "WrongAnimal string constructor is called " << this->type << " is created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src):type(src.type)
{
	std::cout << "WrongAnimal copy constructor is called " << this->type << " is created" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor is called " << this->type << " is removed" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	this->type = src.type;
	return (*this);
}

const std::string	&WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound ~~~~ !" << std::endl;
}
