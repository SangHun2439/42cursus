/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:28:08 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/03 10:30:33 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_mlx *mlx, t_imgset *p_imgset)
{
	p_imgset->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./others/wall_1.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->road = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./others/road.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->c_exit = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./others/c_door.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->o_exit = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./others/o_door.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->shrimp = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./others/shrimp.xpm", &(p_imgset->size), &(p_imgset->size));
	img_init_rst(mlx, p_imgset);
	img_init_lst(mlx, p_imgset);
	img_init_rmv(mlx, p_imgset);
	img_init_lmv(mlx, p_imgset);
}

void	put_backgroung(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y != game->map->height)
	{
		x = 0;
		while (x != game->map->width)
		{
			put_img(game, game->imgset->wall, x, y);
			x++;
		}
		y++;
	}
	display_count(game);
}

void	put_road(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '0')
				put_img(game, game->imgset->road, x, y);
			if (game->map->map[y][x] == 'C')
				put_img(game, game->imgset->road, x, y);
			if (game->map->map[y][x] == 'E')
				put_img(game, game->imgset->road, x, y);
			if (game->map->map[y][x] == 'P')
				put_img(game, game->imgset->road, x, y);
			x++;
		}
		y++;
	}
}

void	put_main(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'C')
				shrimp_put_cnt(game, game->imgset->shrimp, x, y);
			if (game->map->map[y][x] == 'E')
				put_img(game, game->imgset->c_exit, x, y);
			if (game->map->map[y][x] == 'P')
				player_put_get_location(game, game->imgset->rst_turtle[0], \
				x, y);
			x++;
		}
		y++;
	}
}

void	map_init(t_game *game)
{
	game->mlx->mlx_ptr = mlx_init();
	game->mlx->win = mlx_new_window(game->mlx->mlx_ptr, \
	(game->imgset->size) * game->map->width, \
	(game->imgset->size) * game->map->height + 30, "so_long");
	img_init(game->mlx, game->imgset);
	put_backgroung(game);
	put_road(game);
	put_main(game);
}
