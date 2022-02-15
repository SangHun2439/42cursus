/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:25:51 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/15 22:38:12 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog:public Animal
{
	private:
	public:
		Dog();
		~Dog();
		Dog(const Dog &src);
		Dog	&operator=(const Dog &src);
		void	makeSound() const;
};

#endif
