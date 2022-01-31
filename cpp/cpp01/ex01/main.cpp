/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:18:38 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/29 20:56:00 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	*zombie_horde;

	zombie_horde = zombieHorde(5, "brad");
	for (int i = 0; i < 5; i++)
		zombie_horde[i].announce();
	delete[] zombie_horde;
	return (0);
}
