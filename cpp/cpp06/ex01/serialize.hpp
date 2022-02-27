/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:22:25 by sangjeon          #+#    #+#             */
/*   Updated: 2022/02/27 20:23:56 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDERIALIZE_HPP
# define SDERIALIZE_HPP

# include <string>
# include <cstdint>

typedef struct s_Data
{
	char		c;
	int			i;
	std::string	str;
}	Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
