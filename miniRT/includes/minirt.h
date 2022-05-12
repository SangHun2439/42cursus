/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:52:26 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/12 09:54:35 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "minirt_objs.h"
# include "event_operate.h"
# include "read_objs.h"
# include "print_image.h"
# include "ray.h"
# include "vec3.h"

# define SP 1
# define PL 2
# define CY 3
# define DI 4

t_ray	get_camera_ray(int x, int y, t_image *image, t_camera *cam);
void	image_init(t_image *image);
void	objs_init(t_objs ***objs);
t_vec3	ray_color(t_ray *ray, t_objs **objs);
void	render(t_image *image, t_camera *cam, t_objs **objs);
void	camera_init(t_camera *camera);
t_vec3	cam_to_world_point(const t_ray *ray, t_camera *cam);
t_vec3	cam_to_world_vec(const t_ray *ray, t_camera *cam);
int	intersect(t_objs *objs, t_ray *ray, float *t);
int	sol_quadratic(t_quadratic *quadratic);
int	sphere_intersect(t_sphere *sphere, t_ray *ray, float *t);
int	trace(t_objs **objs, t_objs **hit_obj, t_ray *ray, float *t_near);
int	plane_intersect(t_plane	*pl, t_ray *ray, float *t);
t_vec3	ray_at(float t, t_ray ray);
int	disk_intersect(t_disk *disk, t_ray *ray, float *t);
int	cy_intersect(t_cylinder *cy, t_ray *ray, float *t);

#endif
