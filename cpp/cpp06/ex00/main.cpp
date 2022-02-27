/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:18:52 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 15:33:41 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Convert.hpp>
#include <Detect.hpp>

int	main(int argc, char* argv[])
{
	if (argc != 2)
		return (0);
	Detect	detect(static_cast<const char*>(argv[1]));
	Convert*	convert;
	try
	{
		convert = detect.getRightConvert();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	convert->doConvert();
	std::cout << *convert << std::endl;
	delete convert;
	return (0);
}
