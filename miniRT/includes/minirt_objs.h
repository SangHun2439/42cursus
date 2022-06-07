/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_objs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:38:57 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/27 19:10:30 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJS_H
# define MINIRT_OBJS_H

# include "vec3.h"
# include "ray.h"
# include "libft.h"

typedef enum e_unique
{
	UNIQUE_AMBIENT,
	UNIQUE_CAMERA
}	t_unique;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*mlx_image;
	int		*mlx_pixel;
	int		pb;
	int		lb;
	int		endian;
}	t_mlx;

typedef struct s_image
{
	int		width;
	int		height;
	float	ratio;
	t_vec3	**pixel;
}	t_image;

typedef struct s_camera
{
	t_vec3	point;
	t_vec3	ori;
	int		fov;
	float	cam_to_world_matrix[4][4];
}	t_camera;

typedef struct s_sphere
{
	t_vec3	origin;
	float	r;
}	t_sphere;

typedef struct s_plane
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

typedef struct s_light
{
	int		id;
	t_vec3	origin;
	t_vec3	rgb;
	float	bright;
}	t_light;

typedef struct s_surface
{
	t_vec3	p_hit;
	t_vec3	n_hit;
	t_vec3	to_cam;
}	t_surface;

typedef struct s_quadratic
{
	float	a;
	float	b;
	float	c;
	float	x0;
	float	x1;
	float	tmp;
}	t_quadratic;

typedef struct s_objs
{
	int		id;
	void	*shape;
	t_vec3	rgb;
	int		(*intersect)(void *, t_ray *, float *);
	void	(*surface)(void *, t_ray *, float t, t_surface *);
}	t_objs;

typedef struct s_minirt
{
	t_mlx		*mlx;
	t_image		*image;
	t_camera	*cam;
	t_list		*objs;
	t_list		*lights;
	char		*file_name;
	int			unique[2];
}	t_minirt;

#endif
