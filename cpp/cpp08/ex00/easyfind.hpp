/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:50:52 by sangjeon          #+#    #+#             */
/*   Updated: 2022/03/01 20:44:52 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iterator>

template <typename T>
typename T::iterator	easyfind(T& container, int val)
{
	typename T::iterator	iter = container.begin();
	while (iter != container.end() && *iter != val)
		iter++;
	return (iter);
}

#endif
