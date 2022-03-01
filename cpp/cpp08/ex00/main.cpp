/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:50:44 by sangjeon          #+#    #+#             */
/*   Updated: 2022/03/01 20:49:40 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main()
{
	std::vector<int>	a;
	std::list<int>		b;

	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	std::cout << *(easyfind(a, 3)) << std::endl;
	std::cout << *(easyfind(b, 5)) << std::endl;

	if (easyfind(a, 10) == a.end())
		std::cout << "no val" << std::endl;
	if (easyfind(b, 13) == b.end())
		std::cout << "no val" << std::endl;
	return (0);
}
