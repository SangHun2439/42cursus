/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:27:04 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/15 22:37:14 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat:public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &src);
		Cat	&operator=(const Cat &src);
		void	makeSound() const;
};

#endif
