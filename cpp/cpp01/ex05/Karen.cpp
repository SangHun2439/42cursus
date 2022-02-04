/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:15:58 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/03 23:26:12 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Karen.hpp"
#include <iostream>

void	Karen::debug( void )
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain( std::string level )
{
	return (this->*f[level_hash(level)])();
}

int		Karen::level_hash( std::string level )
{
	return (level[0] % 10 % 7);
}

Karen::Karen()
{
	f[level_hash("DEBUG")] = &Karen::debug;
	f[level_hash("INFO")] = &Karen::info;
	f[level_hash("WARNING")] = &Karen::warning;
	f[level_hash("ERROR")] = &Karen::error;
}

Karen::~Karen()
{
}
