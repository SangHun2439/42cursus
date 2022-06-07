/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:35:37 by sangjeon          #+#    #+#             */
/*   Updated: 2022/06/01 22:55:44 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "obj_viewer.h"

t_minirt	*new_minirt(char *filename)
{
	t_minirt	*ret;

	ret = (t_minirt *)ft_calloc_assert(1, sizeof(t_minirt));
	ft_memset(ret, 0, sizeof(t_minirt));
	image_init(&(ret->image));
	rt_init(ret, filename);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_minirt	*rt;

	if (argc != 2)
		ft_error(ERROR_NO_ARG);
	if (!ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
		ft_error(ERROR_NO_RT_FILE);
	rt = new_minirt(argv[1]);
	parser(argv[1], rt);
	view_minirt(rt);
	mlx_hook(rt->mlx->win, X_EVENT_KEY_PRESS, 0, key_press, rt);
	mlx_hook(rt->mlx->win, X_EVENT_RED_BUTTON_PRESS, 0, red_button_press, rt);
	render(rt);
	mlx_loop(rt->mlx->mlx_ptr);
	return (0);
}
