/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:15:17 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/04 12:43:09 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

int	filter_complain(std::string complain)
{
	if (complain == "DEBUG")
		return (1);
	if (complain == "INFO")
		return (2);
	if (complain == "WARNING")
		return (3);
	if (complain == "ERROR")
		return (4);
	return (0);
}

int	main(int argc, char **argv)
{
	Karen		karen;
	int			filter;

	if (argc != 2)
		return (0);
	filter = filter_complain(argv[1]);
	switch (filter)
	{
		case 0:
			std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
			break;
		case 1:
			std::cout << "[ DEBUG ]" << std::endl;
			karen.complain("DEBUG");
			std::cout << std::endl;
		case 2:
			std::cout << "[ INFO ]" << std::endl;
			karen.complain("INFO");
			std::cout << std::endl;
		case 3:
			std::cout << "[ WARNING ]" << std::endl;
			karen.complain("WARNING");
			std::cout << std::endl;
		case 4:
			std::cout << "[ ERROR ]" << std::endl;
			karen.complain("ERROR");
			std::cout << std::endl;
		default:
			break;
	}

}
