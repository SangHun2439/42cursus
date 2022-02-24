/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:28:46 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/24 14:31:21 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat&	operator=(Bureaucrat& src);
		const std::string&	getName() const;
		int					getGrade() const;
		void				incregrade();
		void				decregrade();
		void				signForm(Form& form);

		class GradeTooHighException: public std::exception
		{
			public:
				const char	*what() const _NOEXCEPT;
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char	*what() const _NOEXCEPT;
		};
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
