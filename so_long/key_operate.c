/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_operate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:27:44 by sangjeon          #+#    #+#             */
/*   Updated: 2021/10/29 22:39:48 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	exit(0);
}

int	key_press(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		quit(game->mlx);
	if (key_code == KEY_W)
		w_action(game);
	if (key_code == KEY_A)
		a_action(game);
	if (key_code == KEY_S)
		s_action(game);
	if (key_code == KEY_D)
		d_action(game);
	return (0);
}

int	button_close(t_game *game)
{
	quit(game->mlx);
	return (0);
}

int	std_action(t_game *game)
{
	static int	cnt;
	int			size;

	size = IMG_SIZE;
	cnt++;
	if (cnt == 18000)
		cnt = 0;
	if (!(cnt % 2000))
	{
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
		game->imgset->road, (game->map->p_x) * size, (game->map->p_y) * size);
		if (game->map->right)
			mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
			game->imgset->rst_turtle[cnt / 2000], (game->map->p_x) * size, (game->map->p_y) * size);
		else
			mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win, \
			game->imgset->lst_turtle[cnt / 2000], (game->map->p_x) * size, (game->map->p_y) * size);
	}
	return (0);
}
