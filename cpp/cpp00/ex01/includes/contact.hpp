/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:13:19 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/25 21:41:24 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;
	public:
		contact(void);
		void		set_firstname(std::string str);
		void		set_lastname(std::string str);
		void		set_nickname(std::string str);
		void		set_phonenumber(std::string str);
		void		set_secret(std::string str);
		std::string	get_firstname(void);
		std::string	get_lastname(void);
		std::string	get_nickname(void);
		std::string	get_phonenumber(void);
		std::string	get_secret(void);
};

#endif
