/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:18:14 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/15 22:50:44 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &src);
		Animal(std::string type);
		virtual ~Animal();
		Animal	&operator=(const Animal &src);
		const std::string	&getType() const;
		virtual void	makeSound() const;
};

#endif
