/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:12:54 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/24 19:45:02 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace	my_func
{
	char	to_upper(const char c)
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
		else
			return (c);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	argv++;
	while (*argv)
	{
		i = 0;
		while ((*argv)[i])
		{
			std::cout << my_func::to_upper((*argv)[i]);
			i++;
		}
		argv++;
	}
	std::cout << std::endl;
}
