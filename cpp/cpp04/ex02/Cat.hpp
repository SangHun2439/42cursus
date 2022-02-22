/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:27:04 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/21 17:51:42 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class Cat:public Animal
{
	private:
		Brain	*brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat &src);
		Cat	&operator=(const Cat &src);
		void	makeSound() const;
		void	setBrain(std::string *ideas, int size);
		void	printIdeas() const;
};

#endif
