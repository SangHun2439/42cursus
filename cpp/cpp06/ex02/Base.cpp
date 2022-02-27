/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:48:06 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 21:48:47 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base*	generate(void)
{
	static	int idx;
	int	int_arr[20];

	idx++;
	if (idx == 20)
		idx = 0;
	std::srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < 20; i++)
		int_arr[i] = std::rand();
	switch (int_arr[idx] % 3)
	{
		case 0:
			return (static_cast<Base*>(new A));
		case 1:
			return (static_cast<Base*>(new B));
		default:
			return (static_cast<Base*>(new C));
	}
}

void	identify(Base* p)
{
	if (static_cast<bool>(dynamic_cast<A*>(p)))
		std::cout << "A";
	else if (static_cast<bool>(dynamic_cast<B*>(p)))
		std::cout << "B";
	else if (static_cast<bool>(dynamic_cast<C*>(p)))
		std::cout << "C";
}

void	identify(Base& p)
{
	try
	{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A";
	}
	catch(...)
	{
	}
	try
	{
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "B";
	}
	catch(...)
	{
	}
	try
	{
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "C";
	}
	catch(...)
	{
	}
}
