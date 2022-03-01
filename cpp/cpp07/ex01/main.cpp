/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:43:29 by sangjeon          #+#    #+#             */
/*   Updated: 2022/03/01 15:26:29 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>

void	twice(int a)
{
	std::cout << 2 * a << std::endl;
}

void	hello(std::string a)
{
	std::cout << a + "hello" << std::endl;
}

int	main()
{
	std::string	str_arr[3] = {"a", "b", "c"};
	int			int_arr[5] = {1, 2, 3, 4, 5};
	::iter(str_arr, 3, hello);
	::iter(str_arr, 3, test_func);

	::iter(int_arr, 5, twice);
	::iter(int_arr, 3, test_func);
	return (0);
}
