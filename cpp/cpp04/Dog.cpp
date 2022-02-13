/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:25:39 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 18:10:46 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog():Animal("Dog")
{
	std::cout << "Dog default constructor is called " << this->type << " is created" << std::endl;
}

Dog::Dog(const Dog &src):Animal(src.type)
{
	std::cout << "Dog copy constructor is called " << this->type << " is created" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called " << this->type << " is removed" << std::endl;
}

Dog	&Dog::operator=(const Dog &src)
{
	this->type = src.type;
	return (*this);
}
