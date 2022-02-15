/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:27:56 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/15 23:00:47 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat():WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor is called " << this->type << " is created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src):WrongAnimal(src.type)
{
	std::cout << "WrongCat copy constructor is called " << this->type << " is created" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor is called " << this->type << " is removed" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	this->type = src.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat sound ~~~~ !" << std::endl;
}
