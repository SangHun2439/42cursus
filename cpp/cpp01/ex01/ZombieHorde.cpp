/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:28:02 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/29 20:53:34 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*zombie_horde;
	int		id;

	zombie_horde = new Zombie[N];
	id = 0;
	while (id < N)
	{
		zombie_horde[id].set_name(name + std::to_string(id));
		id++;
	}
	return (zombie_horde);
}
