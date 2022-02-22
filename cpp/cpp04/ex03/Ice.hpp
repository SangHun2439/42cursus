/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:12:43 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/22 12:13:04 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice:public AMateria
{
	public:
		Ice();
		Ice(const Ice &src);
		Ice	&operator=(const Ice &src);
		~Ice();

		Ice	*clone() const;
		void	use(ICharacter& target);
};

#endif
