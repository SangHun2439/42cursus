/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:49:22 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/13 12:39:58 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					val;
		static const int	b_fract = 8;
	public:
		Fixed();
		Fixed(const Fixed &origin);
		Fixed(const int to_convert);
		Fixed(const float to_convert);
		~Fixed();

		Fixed	&operator=(const Fixed &origin);
		bool	operator>(const Fixed &a);
		bool	operator<(const Fixed &a);
		bool	operator>=(const Fixed &a);
		bool	operator<=(const Fixed &a);
		bool	operator==(const Fixed &a);
		bool	operator!=(const Fixed &a);
		Fixed	operator+(const Fixed &a);
		Fixed	operator-(const Fixed &a);
		Fixed	operator*(const Fixed &a);
		Fixed	operator/(const Fixed &a);
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif
