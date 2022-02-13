/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:18:08 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 18:58:25 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal():type("Unknown")
{
	std::cout << "Animal default constructor is called " << this->type << " is created" << std::endl;
}

Animal::Animal(std::string type):type(type)
{
	std::cout << "Animal string constructor is called " << this->type << " is created" << std::endl;
}

Animal::Animal(const Animal &src):type(src.type)
{
	std::cout << "Animal copy constructor is called " << this->type << " is created" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor is called " << this->type << " is removed" << std::endl;
}

Animal	&Animal::operator=(const Animal &src)
{
	this->type = src.type;
	return (*this);
}

const std::string	&Animal::getType() const
{
	return (type);
}

