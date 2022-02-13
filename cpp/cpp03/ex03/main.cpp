/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:05:31 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 16:40:45 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	DiamondTrap	a("brad");
	DiamondTrap	b;
	DiamondTrap	c(a);

	a.attack("joy");
	b.attack("joy");
	b = DiamondTrap("st");
	b.attack("joy");
	c.attack("joy");
	a.highFivesGuys();
	b.highFivesGuys();
	c.highFivesGuys();
	a.guardGate();
	b.guardGate();
	c.guardGate();
	a.whoAmI();
	b.whoAmI();
	c.whoAmI();
}
