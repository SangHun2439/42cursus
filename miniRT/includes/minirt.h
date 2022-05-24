/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:52:26 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/24 23:12:45 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "minirt_objs.h"
# include "event_operate.h"
# include "print_image.h"
# include "ray.h"
# include "vec3.h"

# define SP 1
# define PL 2
# define CY 3
# define DI 4

# define A 1
# define L 2

# define UP 1
# define DOWN 2

# define RGB_MAX 255.0f

# define DIFFUSE_CONST 0.7f
# define SPECULAR_CONST 0.1f
# define DISTANCE_CONST 0.0001f

t_ray	get_camera_ray(int x, int y, t_image *image, t_camera *cam);
t_vec3	cam_to_world_point(const t_ray *ray, t_camera *cam);
t_vec3	cam_to_world_vec(const t_ray *ray, t_camera *cam);

int		plane_intersect(void *shape, t_ray *ray, float *t);
int		sphere_intersect(void *shape, t_ray *ray, float *t);
int		disk_intersect(void *shape, t_ray *ray, float *t);
int		cy_intersect(void *shape, t_ray *ray, float *t);
void	cy_surface(void *shape, t_ray *ray, float t, t_surface *surface);
void	disk_surface(void *shape, t_ray *ray, float t, t_surface *surface);
void	sphere_surface(void *shape, t_ray *ray, float t, t_surface *surface);
void	plane_surface(void *shape, t_ray *ray, float t, t_surface *surface);

void	read_file_init(char *file_name, t_camera **cam, t_list **objs, t_list **lights);
void	camera_init(t_camera **camera, char **element);
void	set_cam_to_world_matrix(t_camera *camera);
void	image_init(t_image **image);
void	ambient_init(t_list **lights, char **element);
void	light_init(t_list **lights, char **element);
void	sp_pl_obj_init(t_list **objs, char **element, int id);
void	sp_init(t_objs *obj, char **element);
void	pl_init(t_objs *obj, char **element);
void	cy_obj_init(t_list **objs, char **element);
void	disk_obj_init(t_list **objs, const t_objs *for_cp, int direction);
void	disk_init(t_objs *obj_disk, const t_objs *for_cp, int direction);
void	cy_init(t_objs *obj, char **element);

void	ray_trace(t_image *image, t_camera *cam, t_list *objs, t_list *lights);
void	trace_and_setcolor(t_ray *ray, t_list *objs, t_list *lights, t_vec3 *pixel);
void	adjust_rgb(t_vec3 *pixel);
int		trace(t_list *objs, t_objs **hit_obj, t_ray *ray, float *t_near);

t_vec3	ambient_color(t_objs *hit_obj, t_light *light);
int		is_shadow(t_list *objs, t_surface *surface, t_light *light);
t_vec3	diffuse_color(t_objs *hit_obj, t_surface *surface, t_light *light);
t_vec3	specular_color(t_surface *surface, t_light *light);
t_vec3	light_color(t_list *objs, t_objs *hit_obj, t_surface *surface, t_light *light);

void	free_split(char **str_arr);
int		sol_quadratic(t_quadratic *quadratic);
void	all_free(t_image *image, t_camera *cam, t_list *objs, t_list *lights);

void	print_image(t_image *image);

#endif
