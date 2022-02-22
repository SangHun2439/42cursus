/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:44:45 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/22 16:46:44 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

# define INVENTORY_NUM 4

class Character:public ICharacter
{
	private:
		std::string	name;
		AMateria	*inventory[INVENTORY_NUM];
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &src);
		Character	&operator=(const Character &src);
		~Character();

		std::string const	&getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);
};

#endif
