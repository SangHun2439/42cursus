/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_operate2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:29:42 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/03 11:50:36 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	w_action(t_game *game)
{
	if (game->moving == 1)
		return ;
	game->to_x = game->map->p_x;
	game->to_y = game->map->p_y - 1;
	game->moving = 1;
}

void	a_action(t_game *game)
{
	if (game->moving == 1)
		return ;
	game->to_x = game->map->p_x - 1;
	game->to_y = game->map->p_y;
	game->moving = 1;
	game->heading = LEFT;
}

void	s_action(t_game *game)
{
	if (game->moving == 1)
		return ;
	game->to_x = game->map->p_x;
	game->to_y = game->map->p_y + 1;
	game->moving = 1;
}

void	d_action(t_game *game)
{
	if (game->moving == 1)
		return ;
	game->to_x = game->map->p_x + 1;
	game->to_y = game->map->p_y;
	game->moving = 1;
	game->heading = RIGHT;
}
