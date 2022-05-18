/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:20:15 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/18 12:51:40 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	image_init(t_image *image)
{
	int	idx;

	image->ratio = (float)image->width / (float)image->height;
	image->pixel = malloc(sizeof(t_vec3 *) * (image->height));
	if (image->pixel == NULL)
		exit(1);
	idx = 0;
	while (idx < image->height)
	{
		image->pixel[idx] = malloc(sizeof(t_vec3) * image->width);
		if (image->pixel[idx] == NULL)
			exit(1);
		idx++;
	}
}

void	get_surface(t_objs *hit_obj, t_ray *ray, float t, t_surface *surface)
{
	if (hit_obj->id == SP)
		return (sphere_surface(hit_obj, ray, t, surface));
	if (hit_obj->id == PL)
		return (plane_surface(hit_obj, ray, t, surface));
	if (hit_obj->id == CY)
		return (cy_surface(hit_obj, ray, t, surface));
	if (hit_obj->id == DI)
		return (disk_surface(hit_obj, ray, t, surface));
}

t_vec3	ambient_color(t_objs *hit_obj, t_light *light)
{
	return (vec3_multi(hit_obj->rgb, vec3_multi_scalar(light->bright, light->rgb)));
}

int	is_shadow(t_objs **objs, t_surface *surface, t_light *light)
{
	t_ray	light_ray;
	t_vec3	p_to_l;
	float	t_max;
	float	t;

	light_ray.origin = vec3_plus(surface->p_hit, vec3_multi_scalar(0.5, surface->n_hit));
	p_to_l = vec3_minus(light->origin, light_ray.origin);
	t_max = vec3_len(p_to_l);
	light_ray.direction = vec3_unit(p_to_l);
	while (*objs)
	{
		if (intersect(*objs, &light_ray, &t) && t < t_max)
			return (1);
		objs++;
	}
	return (0);
}

t_vec3	diffuse_color(t_objs *hit_obj, t_surface *surface, t_light *light)
{
	float intensity;
	t_vec3	p_to_l;

	p_to_l = vec3_minus(light->origin, surface->p_hit);
	intensity = vec3_dot(surface->n_hit, vec3_unit(p_to_l)) / (vec3_len_squared(p_to_l) * 0.00001);
	if (hit_obj->id == PL && intensity < 0)
		intensity = -intensity;
	else if (intensity < 0)
		intensity = 0;
	return (vec3_multi(hit_obj->rgb, vec3_multi_scalar(intensity, vec3_multi_scalar(light->bright, light->rgb))));
}

t_vec3	specular_color(t_surface *surface, t_light *light, t_ray *ray)
{
	t_vec3	p_to_l;
	t_vec3	p_to_v;
	t_vec3	r;
	float	specular;

	p_to_l = vec3_minus(light->origin, surface->p_hit);
	p_to_v = vec3_unit(vec3_minus(ray->origin, surface->p_hit));
	r = vec3_multi_scalar(2 * vec3_dot(surface->n_hit, p_to_l), surface->n_hit);
	r =vec3_unit(vec3_minus(r, p_to_l));
	specular = vec3_dot(p_to_v, r);
	if (specular < 0)
		specular = 0;
	specular = powf(specular, 50);
	return (vec3_multi_scalar(specular, vec3_multi_scalar(light->bright, light->rgb)));
}

t_vec3	light_color(t_objs **objs, t_objs *hit_obj, t_surface *surface, t_light *light, t_ray *ray)
{
	t_vec3	rgb;

	rgb.e[0] = 0.0;
	rgb.e[1] = 0.0;
	rgb.e[2] = 0.0;
	if (is_shadow(objs, surface, light))
		return (rgb);
	rgb = vec3_plus(rgb, vec3_multi_scalar(0.5, diffuse_color(hit_obj, surface, light)));
	rgb = vec3_plus(rgb, vec3_multi_scalar(0.2, specular_color(surface, light, ray)));
	return (rgb);
}

t_vec3	ray_color(t_ray *ray, t_objs **objs, t_light **lights)
{
	t_vec3	rgb;
	t_objs	*hit_obj;
	t_surface	surface;
	float	t_near;

	hit_obj = 0;
	t_near = INFINITY;
	rgb.e[0] = 0.0;
	rgb.e[1] = 0.0;
	rgb.e[2] = 0.0;
	if (trace(objs, &hit_obj, ray, &t_near))
	{
		get_surface(hit_obj, ray, t_near, &surface);
		while (*lights)
		{
			if ((*lights)->id == A)
				rgb = vec3_plus(rgb, ambient_color(hit_obj, *lights));
			if ((*lights)->id == L)
				rgb = vec3_plus(rgb, light_color(objs, hit_obj, &surface, *lights, ray));
			lights++;
		}
	}
	if (rgb.e[0] > 1.0f)
		rgb.e[0] = 1.0f;
	if (rgb.e[1] > 1.0f)
		rgb.e[1] = 1.0f;
	if (rgb.e[2] > 1.0f)
		rgb.e[2] = 1.0f;
	return (rgb);
}

void	render(t_image *image, t_camera *cam, t_objs **objs, t_light **light)
{
	t_ray	camera_ray;

	for (int j = 0; j < image->height; ++j)
	{
		for (int i = 0; i < image->width; ++i)
		{
			camera_ray = get_camera_ray(i, j, image, cam);
			// printf("Ray<%d> -- position : (%lf, %lf, %lf) direction : (%lf, %lf, %lf)\n", j * image->width + i, camera_ray.origin.e[0], camera_ray.origin.e[1], camera_ray.origin.e[2], camera_ray.direction.e[0], camera_ray.direction.e[1], camera_ray.direction.e[2]);
			image->pixel[j][i] = ray_color(&camera_ray, objs, light);
		}
	}
}
