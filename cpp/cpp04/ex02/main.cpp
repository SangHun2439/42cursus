/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:18:00 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/21 18:38:10 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	Animal* animal_arr[6];
	std::string	a[3] = {"hello", "Brad", "42"};
	std::string	b[2] = {"only", "42"};

	for(int k = 0; k < 6; k++)
	{
		if (k % 2)
			animal_arr[k] = new Cat;
		else
			animal_arr[k] = new Dog;
		std::cout << animal_arr[k]->getType() << k << " is created" << std::endl;
	}
	for(int k = 0; k < 6; k++)
	{
		std::cout << animal_arr[k]->getType() << k << " is deleted" << std::endl;
		delete animal_arr[k];
	}

	Cat cat1;

	cat1.setBrain(a, 3);
	Cat cat2(cat1);
	cat1.setBrain(b, 2);
	std::cout << cat1.getType() << "num1 my idea is " << std::endl;
	cat1.printIdeas();
	std::cout << cat2.getType() << "num2 my idea is " << std::endl;
	cat2.printIdeas();

	Dog dog1;

	dog1.setBrain(a, 3);
	Dog dog2(dog1);
	dog1.setBrain(b, 2);
	std::cout << dog1.getType() << "num1 my idea is " << std::endl;
	cat1.printIdeas();
	std::cout << dog2.getType() << "num2 my idea is " << std::endl;
	dog2.printIdeas();
}
