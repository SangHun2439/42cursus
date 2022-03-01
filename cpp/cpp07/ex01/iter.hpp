/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:43:04 by sangjeon          #+#    #+#             */
/*   Updated: 2022/03/01 15:26:39 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	test_func(T a)
{
	std::cout << a << std::endl;
}

template<typename T1, typename T2>
void	iter(T1* arr, T2 len, void(*func)(T1))
{
	T2	i;

	i = 0;
	while (i < len)
		func(arr[i++]);
}

#endif
