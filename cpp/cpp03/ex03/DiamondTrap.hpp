/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:06:14 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 16:40:59 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap:virtual public FragTrap, virtual public ScavTrap
{
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap	&operator=(const DiamondTrap &src);
		void	attack(std::string const &target);
		void	whoAmI();
};

#endif
