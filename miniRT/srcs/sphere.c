/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:34:29 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/24 18:15:52 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	sphere_intersect(void *shape, t_ray *ray, float *t)
{
	t_quadratic	quadratic;
	t_sphere	*sphere;
	t_vec3		l;

	sphere = shape;
	l = vec3_minus(ray->origin, sphere->origin);
	quadratic.a = vec3_dot(ray->direction, ray->direction);
	quadratic.b = 2 * vec3_dot(ray->direction, l);
	quadratic.c = vec3_dot(l, l) - (sphere->r * sphere->r);
	if(!sol_quadratic(&quadratic))
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
	*t = quadratic.x0;
	return (1);
}

void	sphere_surface(void *shape, t_ray *ray, float t, t_surface *surface)
{
	t_sphere *sphere;

	sphere = shape;
	surface->to_cam = vec3_multi_scalar(-1, ray->direction);
	surface->p_hit = ray_at(t, *ray);
	surface->n_hit = vec3_unit(vec3_minus(surface->p_hit, sphere->origin));
}
