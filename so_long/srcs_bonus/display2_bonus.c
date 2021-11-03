/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:47:14 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/03 11:50:34 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*str_make(t_game *game)
{
	char	*cnt;
	char	*res;
	char	*free_ptr;

	cnt = simple_itoa(game->mv_cnt);
	res = ft_strjoin("Movement Count : ", cnt);
	free(cnt);
	free_ptr = res;
	res = ft_strjoin(res, "       Shrimp Count : ");
	free(free_ptr);
	free_ptr = res;
	cnt = simple_itoa(game->map->col_cnt);
	res = ft_strjoin(res, cnt);
	free(cnt);
	free(free_ptr);
	return (res);
}

void	display_count(t_game *game)
{
	char	*display_str;
	int		i;
	int		j;

	j = 0;
	while (j < 30)
	{
		i = 0;
		while (i < 300)
		{
			mlx_pixel_put(game->mlx->mlx_ptr, game->mlx->win, i, \
			game->map->height * (game->imgset->size) + j, 0);
			i++;
		}
		j++;
	}
	display_str = str_make(game);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win, 5, \
	game->map->height * (game->imgset->size) + 17, 0xffffff, display_str);
	free(display_str);
}

void	mv_end(t_game *game)
{
	game->map->map[game->to_y][game->to_x] = 'P';
	game->map->map[game->map->p_y][game->map->p_x] = '0';
	game->map->p_x = game->to_x;
	game->map->p_y = game->to_y;
	game->moving = 0;
	game->mv_cnt++;
	display_count(game);
}

void	game_clear(t_game *game)
{
	mlx_clear_window(game->mlx->mlx_ptr, game->mlx->win);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win, \
	game->map->width / 2 * 60 - 10, game->map->height / 2 * 60, 0xFFFFFF, \
	"SUCCESS!");
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win, \
	game->map->width / 2 * 60 - 40, game->map->height / 2 * 60 + 30, 0xFFFFFF, \
	"PRESS ESC TO END");
	game->clear = 1;
	game->moving = 0;
}
