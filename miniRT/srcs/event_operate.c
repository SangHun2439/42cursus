/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_operate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:03:16 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/30 13:50:39 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_operate.h"
#include "minirt.h"

void	quit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	exit(0);
}

void	reset(t_minirt *rt)
{
	free(rt->cam);
	rt->cam = 0;
	ft_lstclear(&(rt->objs), free_objs);
	ft_lstclear(&(rt->lights), free);
	rt->unique[UNIQUE_AMBIENT] = 0;
	rt->unique[UNIQUE_CAMERA] = 0;
	parser(rt->file_name, rt);
	render(rt);
}

int	red_button_press(t_minirt *rt)
{
	quit(rt->mlx);
	return (0);
}

int	key_press(int key_code, t_minirt *rt)
{
	if (key_code == KEY_ESC)
		quit(rt->mlx);
	else if (key_code == KEY_R)
		reset(rt);
	return (0);
}

int	render(t_minirt *rt)
{
	int	x;
	int	y;

	ray_trace(rt->image, rt->cam, rt->objs, rt->lights);
	y = 0;
	while (y < rt->image->height)
	{
		x = 0;
		while (x < rt->image->width)
		{
			rt->mlx->mlx_pixel[(y * rt->mlx->lb) + x] = \
			convert_rgb(rt->image->pixel[y][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rt->mlx->mlx_ptr, rt->mlx->win, \
	rt->mlx->mlx_image, 0, 0);
	return (0);
}
