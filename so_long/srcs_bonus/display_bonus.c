/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 12:39:37 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/03 11:50:34 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	st_ani(t_game *game, int frame_per_act)
{
	static int	frame;

	if (!(frame % frame_per_act))
	{
		display_count(game);
		put_img(game, game->imgset->road, game->map->p_x, game->map->p_y);
		if (game->heading == RIGHT)
			put_img(game, game->imgset->rst_turtle[frame / frame_per_act], \
			game->map->p_x, game->map->p_y);
		else
			put_img(game, game->imgset->lst_turtle[frame / frame_per_act], \
			game->map->p_x, game->map->p_y);
	}
	frame++;
	if (frame == frame_per_act * 9)
		frame = 0;
}

void	mv_ani(t_game *game, int frame_per_act)
{
	static int	frame;
	void		**mv_img;

	if (game->heading == LEFT)
		mv_img = game->imgset->lmv_turtle;
	else
		mv_img = game->imgset->rmv_turtle;
	if (!(frame % frame_per_act))
	{
		put_img(game, game->imgset->road, game->map->p_x, game->map->p_y);
		put_img(game, game->imgset->road, game->to_x, game->to_y);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		mv_img[frame / frame_per_act], \
		game->map->p_x * game->imgset->size + \
		(game->to_x - game->map->p_x) * 5 * (frame / frame_per_act + 1), \
		game->map->p_y * game->imgset->size + \
		(game->to_y - game->map->p_y) * 5 * (frame / frame_per_act + 1));
	}
	frame++;
	if (frame == frame_per_act * 12)
	{
		mv_end(game);
		frame = 0;
	}
}

void	eat_ani(t_game *game)
{
	int	x;
	int	y;

	if (game->moving)
		return ;
	game->map->col_cnt--;
	display_count(game);
	if (game->map->col_cnt == 0)
	{
		y = 0;
		while (game->map->map[y])
		{
			x = 0;
			while (game->map->map[y][x])
			{
				if (game->map->map[y][x] == 'E')
				{
					put_img(game, game->imgset->road, x, y);
					put_img(game, game->imgset->o_exit, x, y);
				}
				x++;
			}
			y++;
		}
	}
}

void	clear_ani(t_game *game, int frame_per_act)
{
	static int	frame;
	void		**mv_img;

	if (game->heading == LEFT)
		mv_img = game->imgset->lmv_turtle;
	else
		mv_img = game->imgset->rmv_turtle;
	if (!(frame % frame_per_act))
	{
		put_img(game, game->imgset->road, game->map->p_x, game->map->p_y);
		put_img(game, game->imgset->road, game->to_x, game->to_y);
		put_img(game, game->imgset->o_exit, game->to_x, game->to_y);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		mv_img[frame / frame_per_act], \
		game->map->p_x * game->imgset->size + \
		(game->to_x - game->map->p_x) * 5 * (frame / frame_per_act + 1), \
		game->map->p_y * game->imgset->size + \
		(game->to_y - game->map->p_y) * 5 * (frame / frame_per_act + 1));
	}
	frame++;
	if (frame == frame_per_act * 12)
	{
		frame = 0;
		game_clear(game);
	}
}
