/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:45:08 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/24 16:11:11 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			grade_sign;
		const int			grade_exec;
		bool				is_sign;
	public:
		Form();
		Form(const std::string& name, int grade_sign, int grade_exec);
		Form(const Form &src);
		virtual ~Form();
		Form&	operator=(Form& src);

		const std::string&	getName() const;
		int					getGrade_sign() const;
		int					getGrade_exec() const;
		bool				getIs_sign() const;
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		void				exec_check(Bureaucrat const & executor) const;

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

		class NotSigned: public std::exception
		{
			public:
				const char	*what() const _NOEXCEPT;
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
