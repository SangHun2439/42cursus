/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:38:08 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/22 16:42:02 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

# define MATERIAL_NUM 4

class MateriaSource:public IMateriaSource
{
	private:
		AMateria	*materials[MATERIAL_NUM];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		~MateriaSource();
		MateriaSource	&operator=(const MateriaSource &src);

		void	learnMateria(AMateria *);
		AMateria	*createMateria(std::string const & type);
};

#endif
