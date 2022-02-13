/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:34:32 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 14:52:08 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap: public ClapTrap
{
	private:
	public:
		FragTrap();
		FragTrap(const FragTrap &src);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &src);
		void	highFivesGuys(void);
		void	attack(std::string const &target);
};

#endif
