/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:35:37 by sangjeon          #+#    #+#             */
/*   Updated: 2021/10/29 21:58:30 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	err(void)
{
	ft_putstr_fd("map Error\n", 2);
	return (0);
}

void	init(t_game **game)
{
	*game = malloc(sizeof(t_game));
	(*game)->mlx = malloc(sizeof(t_map));
	(*game)->imgset = malloc(sizeof(t_imgset));
	(*game)->map = malloc(sizeof(t_map));
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	init(&game);
	if (!map_parse(argv[1], game->map))
		return (err());
	map_render(game->map, game->mlx, game->imgset);
	mlx_hook(game->mlx->win, X_EVENT_KEY_PRESS, 0, key_press, game);
	mlx_hook(game->mlx->win, X_EVENT_RED_BUTTON_PRESS, 0, button_close, game);
	mlx_loop_hook(game->mlx->mlx_ptr, std_action, game);
	mlx_loop(game->mlx->mlx_ptr);
}
