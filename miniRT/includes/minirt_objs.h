/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_objs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:38:57 by sangjeon          #+#    #+#             */
/*   Updated: 2022/03/26 12:59:05 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJS_H
# define MINIRT_OBJS_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_objs
{
	int	id;
	t_point	position;
	t_point	n_vec;
	int	r;
	int	g;
	int	b;
}	t_objs;

typedef struct s_minirt
{
	t_mlx	*mlx;

}	t_minirt;

#endif
