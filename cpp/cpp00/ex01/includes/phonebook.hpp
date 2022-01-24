/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:56:43 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/24 19:22:26 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <limits>
# include "contact.hpp"

# define MAX_NUM_CONTACTS 8

class phonebook
{
	private:
		contact	phbook[MAX_NUM_CONTACTS];
		int		idx;
		int		len;
	public:
		void	add(void);
		void	search(void);
		void	print_short(void);
		void	print_detail(int idx);
};

#endif
