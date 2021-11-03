/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:18:39 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/03 11:50:40 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	shrimp_put_cnt(t_game *game, void *img, int x, int y)
{
	put_img(game, img, x, y);
	game->map->col_cnt++;
}

void	player_put_get_location(t_game *game, void *img, int x, int y)
{
	put_img(game, img, x, y);
	game->map->p_x = x;
	game->map->p_y = y;
}
