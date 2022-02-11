/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:04:32 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/11 22:18:21 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	private:
		std::string	name;
		int			HitPoints;
		int			Energy_points;
		int			Attack_damage;
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	setHitPoints( int n );
		void	setEnergy_points( int n );
		void	setAttack_damage( int n );
		std::string	getName() const;
		int		getHitPoints() const;
		int		getEnergy_points() const;
		int		getAttack_damage() const;
};

#endif
