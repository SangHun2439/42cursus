/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:12:46 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 15:16:55 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLECONVERT_HPP
# define DOUBLECONVERT_HPP

# include "Convert.hpp"

class DoubleConvert: public Convert
{
	private:
		double	val;
		bool	overflow;
	public:
		DoubleConvert();
		~DoubleConvert();
		DoubleConvert(const std::string& literal);
		DoubleConvert(const DoubleConvert& src);
		DoubleConvert&	operator=(const DoubleConvert& src);

		void	doConvert();
		char	toChar();
		int		toInt();
		float	toFloat();
		double	toDouble();
};

#endif
