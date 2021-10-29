/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:36:41 by sangjeon          #+#    #+#             */
/*   Updated: 2021/10/29 22:40:23 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 64

# define IMG_SIZE 60

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

typedef	struct s_map
{
	char	**map;
	int		width;
	int		height;
	char	right;
	int		p_x;
	int		p_y;
}	t_map;

typedef	struct s_imgset
{
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

typedef	struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef	struct s_game
{
	t_mlx		*mlx;
	t_imgset	*imgset;
	t_map		*map;
}	t_game;


int		map_parse(char *path, t_map *map_info);
void	split_free(char **split);
void	map_render(t_map *map_info, t_mlx *mlx, t_imgset *imgset);
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

#endif
