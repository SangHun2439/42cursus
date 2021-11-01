/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 12:39:37 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/01 17:24:27 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_count(t_game *game)
{
	char	*cnt;
	int		i;
	int		j;

	j = 0;
	while (j < 30)
	{
		i = 0;
		while (i < 300)
		{
			mlx_pixel_put(game->mlx->mlx_ptr, game->mlx->win, i, game->map->height * (game->imgset->size) + j, 0);
			i++;
		}
		j++;
	}
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win, 5, game->map->height * (game->imgset->size) + 17, 0xffffff, "Movement Count : ");
	cnt = simple_itoa(game->mv_cnt);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win, 5 + 120, game->map->height * (game->imgset->size) + 17, 0xffffff, cnt);
	free(cnt);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win, 5 + 160, game->map->height * (game->imgset->size) + 17, 0xffffff, "Shrimp Count : ");
	cnt = simple_itoa(game->map->col_cnt);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win, 5 + 265, game->map->height * (game->imgset->size) + 17, 0xffffff, cnt);
	free(cnt);
}

void	st_ani(t_game *game, int frame_per_act)
{
	static int	frame;

	if (!(frame % frame_per_act))
	{
		display_count(game);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		game->imgset->road, (game->map->p_x) * (game->imgset->size), (game->map->p_y) * (game->imgset->size));
		if (game->heading == RIGHT)
			mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
			game->imgset->rst_turtle[frame / frame_per_act], (game->map->p_x) * (game->imgset->size), (game->map->p_y) * (game->imgset->size));
		else
			mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
			game->imgset->lst_turtle[frame / frame_per_act], (game->map->p_x) * (game->imgset->size), (game->map->p_y) * (game->imgset->size));
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
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		game->imgset->road, (game->map->p_x) * (game->imgset->size), (game->map->p_y) * (game->imgset->size));
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		game->imgset->road, (game->to_x) * (game->imgset->size), (game->to_y) * (game->imgset->size));
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		mv_img[frame / frame_per_act], \
		game->map->p_x * game->imgset->size + (game->to_x - game->map->p_x) * 5 * (frame / frame_per_act + 1), \
		game->map->p_y * game->imgset->size + (game->to_y - game->map->p_y) * 5 * (frame / frame_per_act + 1));
	}
	frame++;
	if (frame == frame_per_act * 12)
	{
		game->map->map[game->to_y][game->to_x] = 'P';
		game->map->map[game->map->p_y][game->map->p_x] = '0';
		game->map->p_x = game->to_x;
		game->map->p_y = game->to_y;
		frame = 0;
		game->moving = 0;
		game->mv_cnt++;
		display_count(game);
	}
}


void	eat_ani(t_game *game)
{
	if (game->moving)
		return ;
	game->map->col_cnt--;
	display_count(game);
	if (game->map->col_cnt == 0)
	{
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		game->imgset->road, (game->map->e_x) * (game->imgset->size), (game->map->e_y) * (game->imgset->size));
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		game->imgset->o_exit, (game->map->e_x) * (game->imgset->size), (game->map->e_y) * (game->imgset->size));
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
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		game->imgset->road, (game->map->p_x) * (game->imgset->size), (game->map->p_y) * (game->imgset->size));
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		game->imgset->o_exit, (game->to_x) * (game->imgset->size), (game->to_y) * (game->imgset->size));
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		mv_img[frame / frame_per_act], \
		game->map->p_x * game->imgset->size + (game->to_x - game->map->p_x) * 5 * (frame / frame_per_act + 1), \
		game->map->p_y * game->imgset->size + (game->to_y - game->map->p_y) * 5 * (frame / frame_per_act + 1));
	}
	frame++;
	if (frame == frame_per_act * 12)
	{
		frame = 0;
		mlx_clear_window(game->mlx->mlx_ptr, game->mlx->win);
		mlx_string_put(game->mlx->mlx_ptr, game->mlx->win, game->map->width / 2 * 60 - 10, game->map->height / 2 * 60, 0xFFFFFF, "SUCCESS!");
		mlx_string_put(game->mlx->mlx_ptr, game->mlx->win, game->map->width / 2 * 60 - 40, game->map->height / 2 * 60 + 30, 0xFFFFFF, "PRESS ESC TO END");
		game->clear = 1;
		game->moving = 0;
	}
}
