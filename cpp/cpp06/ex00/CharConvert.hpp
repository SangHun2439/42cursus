/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConvert.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:12:46 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/26 20:15:45 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCONVERT_HPP
# define CHARCONVERT_HPP

# include "Convert.hpp"

class CharConvert: public Convert
{
	private:
		char	val;
	public:
		CharConvert();
		~CharConvert();
		CharConvert(const std::string& literal);
		CharConvert(const CharConvert& src);
		CharConvert&	operator=(const CharConvert& src);

		void	doConvert();
		char	toChar();
		int		toInt();
		float	toFloat();
		double	toDouble();
};

#endif
