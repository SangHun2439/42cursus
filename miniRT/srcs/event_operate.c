/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_operate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:03:16 by sangjeon          #+#    #+#             */
/*   Updated: 2022/03/26 12:42:30 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_operate.h"

void	quit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	exit(0);
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
	return (0);
}
