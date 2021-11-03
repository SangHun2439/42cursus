/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:36:41 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/03 12:32:55 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 64

# define WALL 0
# define ROAD 1
# define FOOD 2
# define DOOR 3

# define RIGHT 0
# define LEFT 1

# define CLOSED 1
# define EXIT 2
# define COLLECT 4
# define PLAYER 8
# define RECTANG 16

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_RED_BUTTON_PRESS 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		col_cnt;
}	t_map;

typedef struct s_imgset
{
	int		size;
	void	*wall;
	void	*road;
	void	*c_exit;
	void	*o_exit;
	void	*rst_turtle[9];
	void	*lst_turtle[9];
	void	*rmv_turtle[12];
	void	*lmv_turtle[12];
	void	*shrimp;
}	t_imgset;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_game
{
	t_mlx		*mlx;
	t_imgset	*imgset;
	t_map		*map;
	char		heading;
	char		clear;
	char		moving;
	int			to_x;
	int			to_y;
	int			mv_cnt;
}	t_game;

int		map_parse(char *path, t_map *map_info);
void	split_free(char **split);
void	map_init(t_game *game);
int		key_press(int key_code, t_game *game);
int		button_close(t_game *game);
void	w_action(t_game *game);
void	a_action(t_game *game);
void	s_action(t_game *game);
void	d_action(t_game *game);
int		std_action(t_game *game);
void	img_init_rst(t_mlx *mlx, t_imgset *p_imgset);
void	img_init_lst(t_mlx *mlx, t_imgset *p_imgset);
void	img_init_rmv(t_mlx *mlx, t_imgset *p_imgset);
void	img_init_lmv(t_mlx *mlx, t_imgset *p_imgset);
void	st_ani(t_game *game, int frame_per_act);
void	mv_ani(t_game *game, int frame_per_act);
void	eat_ani(t_game *game);
void	clear_ani(t_game *game, int frame_per_act);
void	display_count(t_game *game);
char	*simple_itoa(int a);
void	put_img(t_game *game, void *img, int x, int y);
void	shrimp_put_cnt(t_game *game, void *img, int x, int y);
void	player_put_get_location(t_game *game, void *img, int x, int y);
void	mv_end(t_game *game);
void	game_clear(t_game *game);
void	print_mv(t_game *game);

#endif
