/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:05:31 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 13:53:18 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	a("brad");
	ScavTrap	b;
	ScavTrap	c(a);

	a.attack("joy");
	b.attack("joy");
	b = ScavTrap("st");
	b.attack("joy");
	c.attack("joy");
	a.guardGate();
	b.guardGate();
	c.guardGate();
}
