/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Detect.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:02:59 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 13:09:01 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DETECT_HPP
# define DETECT_HPP

# include <string>
# include <exception>
# include "Convert.hpp"
# include "CharConvert.hpp"
# include "IntConvert.hpp"
# include "FloatConvert.hpp"
# include "DoubleConvert.hpp"

class Detect
{
	private:
		std::string	literal;

		bool	isChar() const;
		bool	isInt() const;
		bool	isFloat() const;
		bool	isDouble() const;
	public:
		Detect();
		Detect(const char* literal);
		Detect(const Detect& src);
		~Detect();
		Detect&	operator=(const Detect& src);

		Convert*	getRightConvert();

		class NotScalarType:public std::exception
		{
			public:
				const char*	what() const _NOEXCEPT;
		};
};

#endif
