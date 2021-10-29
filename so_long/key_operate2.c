/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_operate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:29:42 by sangjeon          #+#    #+#             */
/*   Updated: 2021/10/29 22:31:06 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_action(t_game *game)
{
	ft_putstr_fd("w\n", 1);
	game = 0;
}

void	a_action(t_game *game)
{
	game = 0;
	ft_putstr_fd("a\n", 1);
}

void	s_action(t_game *game)
{
	game = 0;
	ft_putstr_fd("s\n", 1);
}

void	d_action(t_game *game)
{
	game = 0;
	ft_putstr_fd("d\n", 1);
}
