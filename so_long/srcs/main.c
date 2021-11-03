/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:35:37 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/03 13:02:34 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	err(void)
{
	ft_putstr_fd("Error\nmap is invalid\n", 2);
	return (0);
}

void	init(t_game **game)
{
	*game = malloc(sizeof(t_game));
	(*game)->mlx = malloc(sizeof(t_map));
	(*game)->imgset = malloc(sizeof(t_imgset));
	(*game)->map = malloc(sizeof(t_map));
	(*game)->heading = RIGHT;
	(*game)->imgset->size = 60;
	(*game)->map->col_cnt = 0;
	(*game)->moving = 0;
	(*game)->clear = 0;
	(*game)->to_x = 0;
	(*game)->to_y = 0;
	(*game)->mv_cnt = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	init(&game);
	if (!map_parse(argv[1], game->map))
		return (err());
	map_init(game);
	mlx_hook(game->mlx->win, X_EVENT_KEY_PRESS, 0, key_press, game);
	mlx_hook(game->mlx->win, X_EVENT_RED_BUTTON_PRESS, 0, button_close, game);
	mlx_loop_hook(game->mlx->mlx_ptr, std_action, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
