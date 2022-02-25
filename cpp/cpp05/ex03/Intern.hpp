/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:38:14 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/25 14:06:30 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();
		Intern&	operator=(const Intern& src);
		Form*	makeSform(const std::string& name, const std::string& target);
		Form*	makePform(const std::string& name, const std::string& target);
		Form*	makeRform(const std::string& name, const std::string& target);
		Form*	makeForm(const std::string& name, const std::string& target);

		class NotExistForm: public std::exception
		{
			public:
				public:
				const char	*what() const _NOEXCEPT;
		};
};

#endif
