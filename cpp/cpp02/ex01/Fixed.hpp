/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:49:22 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/04 20:16:58 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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
			Fixed &operator=(const Fixed &origin);
			int		getRawBits( void ) const;
			void	setRawBits( int const raw );
	};

#endif
