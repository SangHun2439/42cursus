/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:34:12 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/11 22:24:59 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap: public ClapTrap
{
	private:
		/* data */
	public:
		ScavTrap(std::string name);
		~ScavTrap();
		void	attack(std::string const &target);
		void	guardGate();
};

#endif
