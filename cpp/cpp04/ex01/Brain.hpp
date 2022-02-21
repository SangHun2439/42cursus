/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:44:20 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/21 17:46:51 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# define IDEAS_NUM 100

class Brain
{
private:
	std::string	ideas[IDEAS_NUM];
	int	size;
public:
	Brain();
	~Brain();
	Brain(const Brain &src);
	Brain	&operator=(const Brain &src);
	void	setIdeas(std::string *ideas, int size);
	void	printIdeas() const;
};


#endif
