/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:20:15 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/24 18:41:16 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	trace(t_list *objs, t_objs **hit_obj, t_ray *ray, float *t_near)
{
	t_objs	*obj;
	float	t;

	while(objs)
	{
		obj = objs->content;
		if ((obj->intersect(obj->shape, ray, &t)) && t < *t_near)
		{
			*t_near = t;
			*hit_obj = obj;
		}
		objs = objs->next;
	}
	if (*hit_obj != 0)
		return (1);
	return (0);
}

void	adjust_rgb(t_vec3 *pixel)
{
	if (pixel->e[0] > 1.0f)
		pixel->e[0] = 1.0f;
	if (pixel->e[1] > 1.0f)
		pixel->e[1] = 1.0f;
	if (pixel->e[2] > 1.0f)
		pixel->e[2] = 1.0f;
}

void	trace_and_setcolor(t_ray *ray, t_list *objs, t_list *lights, t_vec3 *pixel)
{
	t_objs		*hit_obj;
	t_light		*light;
	t_surface	surface;
	float		t_near;

	hit_obj = 0;
	t_near = INFINITY;
	*pixel = get_vec3_same_val(0.0f);
	if (trace(objs, &hit_obj, ray, &t_near))
	{
		hit_obj->surface(hit_obj->shape, ray, t_near, &surface);
		while (lights)
		{
			light = lights->content;
			if (light->id == A)
				*pixel = vec3_plus(*pixel, ambient_color(hit_obj, light));
			if (light->id == L)
				*pixel = vec3_plus(*pixel, light_color(objs, hit_obj, &surface, light));
			lights = lights->next;
		}
	}
	adjust_rgb(pixel);
}


void	ray_trace(t_image *image, t_camera *cam, t_list *objs, t_list *lights)
{
	t_ray	camera_ray;

	for (int j = 0; j < image->height; ++j)
	{
		for (int i = 0; i < image->width; ++i)
		{
			camera_ray = get_camera_ray(i, j, image, cam);
			trace_and_setcolor(&camera_ray, objs, lights, &(image->pixel[j][i]));
		}
	}
}
