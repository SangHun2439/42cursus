/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:28:08 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/01 17:11:49 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_mlx *mlx, t_imgset *p_imgset)
{
	p_imgset->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./others/wall_1.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->road = mlx_xpm_file_to_image(mlx->mlx_ptr, "./others/road.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->c_exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "./others/c_door.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->o_exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "./others/o_door.xpm", &(p_imgset->size), &(p_imgset->size));
	p_imgset->shrimp = mlx_xpm_file_to_image(mlx->mlx_ptr, "./others/shrimp.xpm", &(p_imgset->size), &(p_imgset->size));
	img_init_rst(mlx, p_imgset);
	img_init_lst(mlx, p_imgset);
	img_init_rmv(mlx, p_imgset);
	img_init_lmv(mlx, p_imgset);
}

void	put_backgroung(t_mlx *mlx, t_imgset *p_imgset, t_map *map_info)
{
	int		x;
	int		y;
	char	*cnt;

	y = 0;
	while (y != map_info->height)
	{
		x = 0;
		while (x != map_info->width)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->wall, x * (p_imgset->size), y * (p_imgset->size));
			x++;
		}
		y++;
	}
	mlx_string_put(mlx->mlx_ptr, mlx->win, 5, y * (p_imgset->size) + 17, 0xffffff, "Movement Count : ");
	cnt = simple_itoa(0);
	mlx_string_put(mlx->mlx_ptr, mlx->win, 5 + 120, y * (p_imgset->size) + 17, 0xffffff, cnt);
	mlx_string_put(mlx->mlx_ptr, mlx->win, 5 + 160, y * (p_imgset->size) + 17, 0xffffff, "Shrimp Count : ");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 5 + 265, y * (p_imgset->size) + 17, 0xffffff, cnt);
	free(cnt);
}

void	put_road(t_mlx *mlx, t_imgset *p_imgset, t_map *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			if (map_info->map[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->road, x * (p_imgset->size), y * (p_imgset->size));
			if (map_info->map[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->road, x * (p_imgset->size), y * (p_imgset->size));
			if (map_info->map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->road, x * (p_imgset->size), y * (p_imgset->size));
			if (map_info->map[y][x] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->road, x * (p_imgset->size), y * (p_imgset->size));
			x++;
		}
		y++;
	}
}

void	put_main(t_mlx *mlx, t_imgset *p_imgset, t_map *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			if (map_info->map[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->shrimp, x * (p_imgset->size), y * (p_imgset->size));
				map_info->col_cnt++;
			}
			if (map_info->map[y][x] == 'E')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->c_exit, x * (p_imgset->size), y * (p_imgset->size));
				map_info->e_x = x;
				map_info->e_y = y;
			}
			if (map_info->map[y][x] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, p_imgset->rst_turtle[0], x * (p_imgset->size), y * (p_imgset->size));
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
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, (imgset->size) * map_info->width, (imgset->size) * map_info->height + 30, "so_long");
	img_init(mlx, imgset);
	put_backgroung(mlx, imgset, map_info);
	put_road(mlx, imgset, map_info);
	put_main(mlx, imgset, map_info);
}
