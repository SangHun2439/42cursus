/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:12:29 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/11 17:56:27 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) {

	Point 	a(0.0f, 0.0f);
	Point	b(4.0f, 0.0f);
	Point	c(2.0f, 3.0f);
	Point	point1(3.0f, 1.4f);
	Point	point2(3.0f, 1.6f);

	std :: cout << "point1 : ";
	if (bsp(a, b, c, point1))
		std::cout << "in!" << std::endl;
	else
		std::cout << "out!" << std::endl;

	std :: cout << "point2 : ";
	if (bsp(a, b, c, point2))
		std::cout << "in!" << std::endl;
	else
		std::cout << "out!" << std::endl;

	return 0;
}
