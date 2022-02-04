/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:16:05 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/03 23:21:48 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP
# include <string>

class Karen
{
private:
	void	(Karen::*f[4])(void);
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	int		level_hash( std::string level );
public:
	Karen();
	~Karen();
	void complain( std::string level );
};

#endif
