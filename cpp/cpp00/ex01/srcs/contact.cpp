/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:55:54 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/24 18:45:08 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	contact::set_firstname(std::string str)
{
	first_name = str;
}

void	contact::set_lastname(std::string str)
{
	last_name = str;
}

void	contact::set_nickname(std::string str)
{
	nickname = str;
}

void	contact::set_phonenumber(std::string str)
{
	phone_number = str;
}

void	contact::set_secret(std::string str)
{
	secret = str;
}

std::string	contact::get_firstname(void)
{
	return (first_name);
}


std::string	contact::get_lastname(void)
{
	return (last_name);
}


std::string	contact::get_nickname(void)
{
	return (nickname);
}


std::string	contact::get_phonenumber(void)
{
	return (phone_number);
}


std::string	contact::get_secret(void)
{
	return (secret);
}
