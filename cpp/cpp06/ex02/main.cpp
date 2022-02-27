/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:18:16 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 21:38:10 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int	main()
{
	Base*	test;

	for (int i = 0; i < 10; i++)
	{
		std::cout<< "======== " << i + 1 << " round ========\n";
		test = generate();
		std::cout << "<identify ptr> ";
		std::cout << "this is ";
		identify(test);
		std::cout << std::endl;
		std::cout << "<identify ref> ";
		std::cout << "this is ";
		identify(*test);
		std::cout << '\n' <<std::endl;
		delete test;
	}
	return (0);
}
