/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:28:08 by sangjeon          #+#    #+#             */
/*   Updated: 2021/10/29 22:30:57 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_mlx *mlx, t_imgset *p_imgset)
{
	int	size;

	size = IMG_SIZE;
	p_imgset->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./others/wall_1.xpm", &size, &size);
	p_imgset->road = mlx_xpm_file_to_image(mlx->mlx_ptr, "./others/road.xpm", &size, &size);
	p_imgset->c_exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "./others/c_door.xpm", &size, &size);
	p_imgset->o_exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "./others/o_door.xpm", &size, &size);
	p_imgset->shrimp = mlx_xpm_file_to_image(mlx->mlx_ptr, "./others/shrimp.xpm", &size, &size);
	img_init_rst(mlx, p_imgset);
	img_init_lst(mlx, p_imgset);
	img_init_rmv(mlx, p_imgset);
	img_init_lmv(mlx, p_imgset);
}

void	put_backgroung(t_mlx *mlx, t_imgset *p_imgset, t_map *map_info)
{
	int	size;
	int	x;
	int	y;

	size = IMG_SIZE;
	y = 0;
	while (y != map_info->height)
	{
		x = 0;
		while (x != map_info->width)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->wall, x * size, y * size);
			x++;
		}
		y++;
	}
}

void	put_road(t_mlx *mlx, t_imgset *p_imgset, t_map *map_info)
{
	int	size;
	int	x;
	int	y;

	size = IMG_SIZE;
	y = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			if (map_info->map[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->road, x * size, y * size);
			if (map_info->map[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->road, x * size, y * size);
			if (map_info->map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->road, x * size, y * size);
			if (map_info->map[y][x] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->road, x * size, y * size);
			x++;
		}
		y++;
	}
}

void	put_main(t_mlx *mlx, t_imgset *p_imgset, t_map *map_info)
{
	int	size;
	int	x;
	int	y;

	size = IMG_SIZE;
	y = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			if (map_info->map[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->shrimp, x * size, y * size);
			if (map_info->map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->c_exit, x * size, y * size);
			if (map_info->map[y][x] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->rst_turtle[0], x * size, y * size);
				map_info->p_x = x;
				map_info->p_y = y;
			}
			x++;
		}
		y++;
	}
}

void	map_render(t_map *map_info, t_mlx *mlx, t_imgset *imgset)
{
	int			size;

	size = IMG_SIZE;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, size * map_info->width, size * map_info->height, "so_long");
	img_init(mlx, imgset);
	put_backgroung(mlx, imgset, map_info);
	put_road(mlx, imgset, map_info);
	put_main(mlx, imgset, map_info);
}
