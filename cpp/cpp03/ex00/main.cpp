/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:05:31 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 13:32:13 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("brad");
	ClapTrap	b;
	ClapTrap	c(a);

	a.attack("joy");
	a.takeDamage(5);
	a.beRepaired(3);
	b.attack("joy");
	b.takeDamage(5);
	b.beRepaired(3);
	b = ClapTrap("st");
	b.attack("joy");
	b.takeDamage(5);
	b.beRepaired(3);
	c.attack("joy");
	c.takeDamage(5);
	c.beRepaired(3);
}
