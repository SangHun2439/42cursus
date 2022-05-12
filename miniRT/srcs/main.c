/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:35:37 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/11 16:51:07 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_init(t_minirt* rt)
{
	rt->mlx = malloc(sizeof(t_mlx));
	if (!(rt->mlx))
		exit(0);
	rt->mlx->mlx_ptr = mlx_init();
	rt->mlx->win = mlx_new_window(rt->mlx->mlx_ptr, 800, 600, "miniRT");
}

int	main(int argc, char **argv)
{
	// t_minirt	*rt;

	// if (argc != 2)
		// return (0);
	// read_objs(argv[1]);
	// rt = malloc(sizeof(t_minirt));
	// if (!rt)
	// 	exit(0);
	// rt_init(rt);
	// mlx_hook(rt->mlx->win, X_EVENT_KEY_PRESS, 0, key_press, rt);
	// mlx_hook(rt->mlx->win, X_EVENT_RED_BUTTON_PRESS, 0, red_button_press, rt);
	// // mlx_loop_hook(game->mlx->mlx_ptr, std_action, game);
	// mlx_loop(rt->mlx->mlx_ptr);

	(void)argc;
	(void)argv;
	t_image	*image;
	t_camera	*cam;
	t_objs		**objs;

	image = malloc(sizeof(t_image));
	if (image == NULL)
		return (1);
	cam = malloc(sizeof(t_camera));
	if (cam == NULL)
		return (1);
	image->width = 800;
	image->height = 600;
	image->fov = 70;
	objs_init(&objs);
	image_init(image);
	camera_init(cam);
	render(image, cam, objs);
	print_image(image);
	return (0);
}
