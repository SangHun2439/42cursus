/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:30:55 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/24 18:16:21 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	cy_intersect(void *shape, t_ray *ray, float *t)
{
	t_vec3	vec_o;
	t_vec3	vec_d;
	t_vec3	vec_e;
	t_quadratic	quadratic;
	t_cylinder	*cy;

	cy = shape;
	vec_d = vec3_cross(ray->direction, cy->n);
	if (vec3_len_squared(vec_d) <= 1e-6)
		return (0);
	vec_o = vec3_cross(ray->origin, cy->n);
	vec_e = vec3_cross(cy->origin, cy->n);
	quadratic.a = vec3_len_squared(vec_d);
	quadratic.b = 2 * (vec3_dot(vec_o, vec_d) - vec3_dot(vec_d, vec_e));
	quadratic.c = vec3_len_squared(vec_o) + vec3_len_squared(vec_e) - 2 * vec3_dot(vec_o, vec_e) - cy->r * cy->r;
	if (!sol_quadratic(&quadratic))
		return (0);
	if (quadratic.x0 > quadratic.x1)
	{
		quadratic.tmp = quadratic.x0;
		quadratic.x0 = quadratic.x1;
		quadratic.x1 = quadratic.tmp;
	}
	if (quadratic.x0 < 0)
	{
		quadratic.x0 = quadratic.x1;
		if (quadratic.x0 < 0)
			return (0);
	}
	quadratic.tmp = vec3_dot(vec3_minus(ray_at(quadratic.x0, *ray), cy->origin), cy->n);
	if (quadratic.tmp < 0 || quadratic.tmp > cy->h)
		return (0);
	*t = quadratic.x0;
	return (1);
}

int	disk_intersect(void *shape, t_ray *ray, float *t)
{
	t_plane	pl;
	t_vec3	p;
	t_disk	*disk;
	float	tmp;

	disk = shape;
	pl.n = disk->n;
	pl.origin = disk->origin;
	if (plane_intersect(&pl, ray, &tmp))
	{
		p = ray_at(tmp, *ray);
		if (vec3_len(vec3_minus(p, disk->origin)) <= disk->r)
		{
			*t = tmp;
			return (1);
		}
	}
	return (0);
}

void	cy_surface(void *shape, t_ray *ray, float t, t_surface *surface)
{
	t_cylinder *cy;
	t_vec3		ep;
	t_vec3		ne;

	cy = shape;
	surface->to_cam = vec3_multi_scalar(-1, ray->direction);
	surface->p_hit = ray_at(t, *ray);
	ep = vec3_minus(surface->p_hit, cy->origin);
	ne = vec3_multi_scalar(vec3_dot(ep, cy->n), cy->n);
	surface->n_hit = vec3_unit(vec3_minus(ep, ne));
}

void	disk_surface(void *shape, t_ray *ray, float t, t_surface *surface)
{
	t_disk *disk;

	disk = shape;
	surface->to_cam = vec3_multi_scalar(-1, ray->direction);
	surface->p_hit = ray_at(t, *ray);
	surface->n_hit = disk->n;
}
