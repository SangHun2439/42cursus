/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:34:12 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 13:35:19 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap: public ClapTrap
{
	private:
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &src);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &src);
		void	attack(std::string const &target);
		void	guardGate();
};

#endif
