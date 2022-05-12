/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_objs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:38:57 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/12 09:30:48 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJS_H
# define MINIRT_OBJS_H

# include "vec3.h"
# include "ray.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_minirt
{
	t_mlx	*mlx;

}	t_minirt;

typedef	struct s_camera
{
	t_vec3	point;
	t_vec3	ori;
	float	cam_to_world_matrix[4][4];
}	t_camera;

typedef struct s_image
{
	int		width;
	int		height;
	float	ratio;
	int		fov;
	t_vec3	**pixel;
}	t_image;

typedef struct	s_objs
{
	int		id;
	void	*real;
	t_vec3	rgb;
}	t_objs;

typedef struct s_sphere
{
	t_vec3	origin;
	float	r;
}	t_sphere;

typedef struct	s_plane
{
	t_vec3	origin;
	t_vec3	n;
}	t_plane;

typedef struct s_disk
{
	t_vec3	origin;
	t_vec3	n;
	float	r;
}	t_disk;

typedef struct s_cylinder
{
	t_vec3	origin;
	t_vec3	n;
	float	r;
	float	h;
}	t_cylinder;

typedef struct s_quadratic
{
	float	a;
	float	b;
	float	c;
	float	x0;
	float	x1;
	float	tmp;
}	t_quadratic;


#endif
