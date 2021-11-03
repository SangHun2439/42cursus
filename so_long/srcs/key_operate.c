/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_operate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:27:44 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/03 12:49:17 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	exit(0);
}

int	check_tile(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == '1')
		return (WALL);
	if (game->map->map[y][x] == 'C')
		return (FOOD);
	if (game->map->map[y][x] == 'E')
		return (DOOR);
	return (ROAD);
}

int	key_press(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		quit(game->mlx);
	if (key_code == KEY_W)
		w_action(game);
	if (key_code == KEY_A)
		a_action(game);
	if (key_code == KEY_S)
		s_action(game);
	if (key_code == KEY_D)
		d_action(game);
	return (0);
}

int	button_close(t_game *game)
{
	quit(game->mlx);
	return (0);
}

int	std_action(t_game *game)
{
	if (game->clear)
		return (0);
	if (game->moving)
	{
		if (check_tile(game, game->to_x, game->to_y) == WALL)
			game->moving = 0;
		else if (check_tile(game, game->to_x, game->to_y) == ROAD)
			mv_ani(game, 500);
		else if (check_tile(game, game->to_x, game->to_y) == FOOD)
		{
			mv_ani(game, 500);
			eat_ani(game);
		}
		else if (game->map->col_cnt == 0)
			clear_ani(game, 500);
		else
			game->moving = 0;
	}
	else
		st_ani(game, 1500);
	return (0);
}
