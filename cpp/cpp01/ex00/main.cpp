/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:18:38 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/29 19:21:32 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie *heap_zombie;
	Zombie stack_Zombie("brad");

	heap_zombie = newZombie("joy");
	heap_zombie->announce();
	stack_Zombie.announce();
	delete heap_zombie;
	randomChump("chump");
}
