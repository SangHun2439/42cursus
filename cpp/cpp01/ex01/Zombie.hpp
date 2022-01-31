/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:49:17 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/29 20:52:36 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void	announce(void);
		void	set_name(std::string name);
};

Zombie	*zombieHorde( int N, std::string name );

#endif
