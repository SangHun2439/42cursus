/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:13:58 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/22 12:13:36 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure:public AMateria
{
	public:
		Cure();
		Cure(const Cure &src);
		Cure	&operator=(const Cure &src);
		~Cure();

		Cure	*clone() const;
		void	use(ICharacter& target);
};

#endif
