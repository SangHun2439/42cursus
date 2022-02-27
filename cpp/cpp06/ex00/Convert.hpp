/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:29:06 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 16:17:52 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cmath>

class Convert
{
	protected:
		std::string			literal;
		const std::string	type;
	public:
		Convert();
		Convert(const std::string& literal, const std::string& type);
		Convert(const Convert& src);
		virtual ~Convert();
		Convert&	operator=(const Convert& src);

		const std::string&	getLiteral() const;
		const std::string&	getType() const;
		void				setLiteral(const std::string& literal);
		virtual void		doConvert() = 0;

		virtual char		toChar() = 0;
		virtual int			toInt() = 0;
		virtual float		toFloat() = 0;
		virtual double		toDouble() = 0;

		class Impossible: public std::exception
		{
			public:
				const char*	what() const _NOEXCEPT;
		};
		class NonDisplayable: public std::exception
		{
			public:
				const char*	what() const _NOEXCEPT;
		};
};

std::ostream&	operator<<(std::ostream& os, Convert& convert);

#endif
