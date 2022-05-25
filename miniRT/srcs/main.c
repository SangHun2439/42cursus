/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:35:37 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/25 10:33:48 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minirt	*rt;

	if (argc != 2)
		return (0);
	rt = malloc(sizeof(t_minirt));
	if (!rt)
		return (1);
	rt->objs = 0;
	rt->lights = 0;
	image_init(&(rt->image));
	rt_init(rt, argv[1]);
	read_file_init(argv[1], &(rt->cam), &(rt->objs), &(rt->lights));
	mlx_hook(rt->mlx->win, X_EVENT_KEY_PRESS, 0, key_press, rt);
	mlx_hook(rt->mlx->win, X_EVENT_RED_BUTTON_PRESS, 0, red_button_press, rt);
	mlx_loop_hook(rt->mlx->mlx_ptr, render, rt);
	mlx_loop(rt->mlx->mlx_ptr);
	all_free(rt->image, rt->cam, rt->objs, rt->lights);
	return (0);
}
