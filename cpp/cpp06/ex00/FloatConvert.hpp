/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatConvert.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:12:46 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 15:17:03 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATCONVERT_HPP
# define FLOATCONVERT_HPP

# include "Convert.hpp"

class FloatConvert: public Convert
{
	private:
		float	val;
		bool	overflow;
	public:
		FloatConvert();
		~FloatConvert();
		FloatConvert(const std::string& literal);
		FloatConvert(const FloatConvert& src);
		FloatConvert&	operator=(const FloatConvert& src);

		void	doConvert();
		char	toChar();
		int		toInt();
		float	toFloat();
		double	toDouble();
};

#endif
