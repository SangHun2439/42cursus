/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:56:43 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/25 21:57:03 by sangjeon         ###   ########.fr       */
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
		void	print_short(void);
		void	print_detail(int idx);
		void	format_print(std::string str, int end);
	public:
		phonebook(void);
		void	add(void);
		void	search(void);
};

#endif
