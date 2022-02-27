/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConvert.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:12:46 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 14:15:21 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTCONVERT_HPP
# define INTCONVERT_HPP

# include "Convert.hpp"

class IntConvert: public Convert
{
	private:
		int		val;
		bool	overflow;
	public:
		IntConvert();
		~IntConvert();
		IntConvert(const std::string& literal);
		IntConvert(const IntConvert& src);
		IntConvert&	operator=(const IntConvert& src);

		void	doConvert();
		char	toChar();
		int		toInt();
		float	toFloat();
		double	toDouble();
};

#endif
