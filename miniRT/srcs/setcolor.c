/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:22:06 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/24 19:53:46 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	ambient_color(t_objs *hit_obj, t_light *light)
{
	return (vec3_multi(hit_obj->rgb, vec3_multi_scalar(light->bright, light->rgb)));
}

int	is_shadow(t_list *objs, t_surface *surface, t_light *light)
{
	t_ray	light_ray;
	t_objs	*obj;
	float	t_max;
	float	t;

	light_ray.origin = vec3_plus(surface->p_hit, vec3_multi_scalar(0.5, surface->n_hit));
	t_max = vec3_len(vec3_minus(light->origin, light_ray.origin));
	light_ray.direction = vec3_unit(vec3_minus(light->origin, light_ray.origin));
	t = INFINITY;
	while (objs)
	{
		obj = objs->content;
		if (obj->intersect(obj->shape, &light_ray, &t) && t < t_max)
			return (1);
		objs = objs->next;
	}
	return (0);
}

t_vec3	diffuse_color(t_objs *hit_obj, t_surface *surface, t_light *light)
{
	float intensity;
	t_vec3	p_to_l;

	p_to_l = vec3_minus(light->origin, surface->p_hit);
	intensity = vec3_dot(surface->n_hit, vec3_unit(p_to_l));
	if (intensity < 0)
		intensity = 0;
	return (vec3_multi(hit_obj->rgb, vec3_multi_scalar(intensity * light->bright / (vec3_len_squared(p_to_l) * DISTANCE_CONST), light->rgb)));
}

t_vec3	specular_color(t_surface *surface, t_light *light)
{
	t_vec3	p_to_l;
	t_vec3	r;
	float	specular;

	p_to_l = vec3_minus(light->origin, surface->p_hit);
	r = vec3_multi_scalar(2 * vec3_dot(surface->n_hit, p_to_l), surface->n_hit);
	r = vec3_unit(vec3_minus(r, p_to_l));
	specular = vec3_dot(surface->to_cam, r);
	if (specular < 0)
		specular = 0;
	specular = powf(specular, 50);
	return vec3_multi_scalar(specular * light->bright / (vec3_len_squared(p_to_l) * DISTANCE_CONST), light->rgb);
}

t_vec3	light_color(t_list *objs, t_objs *hit_obj, t_surface *surface, t_light *light)
{
	t_vec3	rgb;

	rgb.e[0] = 0.0;
	rgb.e[1] = 0.0;
	rgb.e[2] = 0.0;
	if (is_shadow(objs, surface, light))
		return (rgb);
	rgb = vec3_plus(rgb, vec3_multi_scalar(DIFFUSE_CONST, diffuse_color(hit_obj, surface, light)));
	rgb = vec3_plus(rgb, vec3_multi_scalar(SPECULAR_CONST, specular_color(surface, light)));
	return (rgb);
}
