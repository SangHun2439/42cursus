/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:25:02 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/24 18:29:56 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(int argc, char **argv)
{
	std::string	input;
	phonebook	my_book;

	(void)argv;
	if (argc != 1)
		return (0);
	std::cout << "Welcome to my phone book!!" << std::endl;
	std::cout << "Please enter one of commands among EXIT, ADD and SEARCH" << std::endl;
	while (std::cin >> input)
	{
		if (input == "EXIT")
			return (0);
		if (input == "ADD")
			my_book.add();
		else if (input == "SEARCH")
			my_book.search();
		std::cout << "Please enter one of commands among EXIT, ADD and SEARCH" << std::endl;
	}
}
