/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:16:16 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/29 23:38:54 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
	private:
		Weapon		*weapon;
		std::string	name;
	public:
		HumanB( std::string name );
		~HumanB();
		void	setWeapon( Weapon &weapon );
		void	attack();
};

#endif
