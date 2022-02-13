/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:05:31 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 14:51:10 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	a("brad");
	FragTrap	b;
	FragTrap	c(a);

	a.attack("joy");
	b.attack("joy");
	b = FragTrap("st");
	b.attack("joy");
	c.attack("joy");
	a.highFivesGuys();
	b.highFivesGuys();
	c.highFivesGuys();
}
