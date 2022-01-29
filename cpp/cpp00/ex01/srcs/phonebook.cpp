/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:40:16 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/29 12:01:44 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

phonebook::phonebook(void)
{
	idx = 0;
	len = 0;
}

void	phonebook::format_print(std::string str, int end)
{
	int	len;

	len = str.length();
	if (len > 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		len = 10 - len;
		std::cout << str;
		while (len--)
			std::cout << " ";
	}
	if (!end)
		std::cout << "|";
	else
		std::cout << std::endl;
}

void	phonebook::print_short(void)
{
	int	i;

	i = 0;
	while (i < len)
	{
		format_print(std::to_string(i), 0);
		format_print(phbook[i].get_firstname(), 0);
		format_print(phbook[i].get_lastname(), 0);
		format_print(phbook[i].get_nickname(), 1);
		i++;
	}
}

void	phonebook::print_detail(int idx)
{
	std::cout << phbook[idx].get_firstname() << std::endl;
	std::cout << phbook[idx].get_lastname() << std::endl;
	std::cout << phbook[idx].get_nickname() << std::endl;
	std::cout << phbook[idx].get_phonenumber() << std::endl;
	std::cout << phbook[idx].get_secret() << std::endl;
}

void	phonebook::add(void)
{
	std::string	input;
	std::cout << "please enter first name :";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);
	phbook[idx].set_firstname(input);
	std::cout << "please enter last name :";
	std::getline(std::cin, input);
	phbook[idx].set_lastname(input);
	std::cout << "please enter nickname :";
	std::getline(std::cin, input);
	phbook[idx].set_nickname(input);
	std::cout << "please enter phone number :";
	std::getline(std::cin, input);
	phbook[idx].set_phonenumber(input);
	std::cout << "please enter dark secret :";
	std::getline(std::cin, input);
	phbook[idx].set_secret(input);
	std::cout << "add success!" << std::endl;
	idx++;
	if (idx == MAX_NUM_CONTACTS)
		idx = 0;
	if (len < MAX_NUM_CONTACTS)
		len++;
}

void	phonebook::search(void)
{
	int	select;

	print_short();
	std::cout << "select index of the desired entry :";
	std::cin >> select;
	if (select >= len || std::cin.fail())
	{
		std::cout << "wrong index" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		print_detail(select);
	}
}
