/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:25:51 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/21 17:53:02 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog:public Animal
{
	private:
		Brain	*brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog &src);
		Dog	&operator=(const Dog &src);
		void	makeSound() const;
		void	setBrain(std::string *ideas, int size);
		void	printIdeas() const;
};

#endif
