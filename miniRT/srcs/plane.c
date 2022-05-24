/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:36:13 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/24 19:00:29 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	plane_intersect(void *shape, t_ray *ray, float *t)
{
	t_plane	*pl;
	float	tmp;

	pl = shape;
	tmp = vec3_dot(ray->direction, pl->n);
	if (tmp > 1e-6 || tmp < -1e-6)
	{
		*t = vec3_dot(vec3_minus(pl->origin, ray->origin), pl->n) / tmp;
		if (*t >= 0)
			return (1);
	}
	return (0);
}

void	plane_surface(void *shape, t_ray *ray, float t, t_surface *surface)
{
	t_plane *plane;

	plane = shape;
	surface->to_cam = vec3_multi_scalar(-1, ray->direction);
	surface->p_hit = ray_at(t, *ray);
	surface->n_hit = plane->n;
	if (vec3_dot(surface->n_hit, ray->direction) > 0)
		surface->n_hit = vec3_multi_scalar(-1, surface->n_hit);
}
