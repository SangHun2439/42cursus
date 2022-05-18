/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:33:37 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/18 12:48:17 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	objs_init(t_objs ***objs, t_light ***light)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_disk		*disk;
	int			i;

	*light = malloc(sizeof(t_light *) * 3);
	i = 0;

	(*light)[i] = malloc(sizeof(t_light));
	(*light)[i]->id = A;
	(*light)[i]->bright = 0.2;
	(*light)[i]->rgb.e[0] = 1.0;
	(*light)[i]->rgb.e[1] = 1.0;
	(*light)[i]->rgb.e[2] = 1.0;
	i++;

	(*light)[i] = malloc(sizeof(t_light));
	(*light)[i]->id = L;
	(*light)[i]->bright = 1.0;
	(*light)[i]->origin.e[0] = 0;
	(*light)[i]->origin.e[1] = 100;
	(*light)[i]->origin.e[2] = -50;
	(*light)[i]->rgb.e[0] = 1.0;
	(*light)[i]->rgb.e[1] = 1.0;
	(*light)[i]->rgb.e[2] = 1.0;
	i++;

	(*light)[i] = 0;

	*objs = malloc(sizeof(t_objs *) * 7);
	i = 0;

	(*objs)[i] = malloc(sizeof(t_objs));
	(*objs)[i]->id = SP;
	(*objs)[i]->rgb.e[0] = 0.7;
	(*objs)[i]->rgb.e[1] = 0.3;
	(*objs)[i]->rgb.e[2] = 0.3;
	sphere = malloc(sizeof(t_sphere));
	sphere->origin.e[0] = 0;
	sphere->origin.e[1] = 0;
	sphere->origin.e[2] = 50;
	sphere->r = 20;
	(*objs)[i]->shape = sphere;
	i++;

	(*objs)[i] = malloc(sizeof(t_objs));
	(*objs)[i]->id = PL;
	(*objs)[i]->rgb.e[0] = 0.3;
	(*objs)[i]->rgb.e[1] = 0.7;
	(*objs)[i]->rgb.e[2] = 0.3;
	plane = malloc(sizeof(t_plane));
	plane->origin.e[0] = 0;
	plane->origin.e[1] = 0;
	plane->origin.e[2] = 300;
	plane->n.e[0] = 1;
	plane->n.e[1] = 1;
	plane->n.e[2] = 1;
	plane->n = vec3_unit(plane->n);
	(*objs)[i]->shape = plane;
	i++;

	(*objs)[i] = malloc(sizeof(t_objs));
	(*objs)[i]->id = PL;
	(*objs)[i]->rgb.e[0] = 0.3;
	(*objs)[i]->rgb.e[1] = 0.3;
	(*objs)[i]->rgb.e[2] = 0.7;
	plane = malloc(sizeof(t_plane));
	plane->origin.e[0] = 0;
	plane->origin.e[1] = 0;
	plane->origin.e[2] = 200;
	plane->n.e[0] = 1;
	plane->n.e[1] = -1;
	plane->n.e[2] = 1;
	plane->n = vec3_unit(plane->n);
	(*objs)[i]->shape = plane;
	i++;

	(*objs)[i] = malloc(sizeof(t_objs));
	(*objs)[i]->id = CY;
	(*objs)[i]->rgb.e[0] = 0.6;
	(*objs)[i]->rgb.e[1] = 0.8;
	(*objs)[i]->rgb.e[2] = 0.1;
	cylinder = malloc(sizeof(t_cylinder));
	cylinder->origin.e[0] = -40.5;
	cylinder->origin.e[1] = 10;
	cylinder->origin.e[2] = 10;
	cylinder->n.e[0] = 1;
	cylinder->n.e[1] = 1;
	cylinder->n.e[2] = 1;
	cylinder->n = vec3_unit(cylinder->n);
	cylinder->r = 14.2 / 2;
	cylinder->h = 42.5;
	(*objs)[i]->shape = cylinder;
	i++;

	(*objs)[i] = malloc(sizeof(t_objs));
	(*objs)[i]->id = DI;
	(*objs)[i]->rgb.e[0] = 0.6;
	(*objs)[i]->rgb.e[1] = 0.8;
	(*objs)[i]->rgb.e[2] = 0.1;
	disk = malloc(sizeof(t_disk));
	disk->origin = cylinder->origin;
	disk->n = vec3_multi_scalar(-1, cylinder->n);
	disk->r = cylinder->r;
	(*objs)[i]->shape = disk;
	i++;

	(*objs)[i] = malloc(sizeof(t_objs));
	(*objs)[i]->id = DI;
	(*objs)[i]->rgb.e[0] = 0.6;
	(*objs)[i]->rgb.e[1] = 0.8;
	(*objs)[i]->rgb.e[2] = 0.1;
	disk = malloc(sizeof(t_disk));
	disk->origin = vec3_plus(cylinder->origin, vec3_multi_scalar(cylinder->h, cylinder->n));
	disk->n = cylinder->n;
	disk->r = cylinder->r;
	(*objs)[i]->shape = disk;
	i++;

	(*objs)[i] = 0;
}

int	trace(t_objs **objs, t_objs **hit_obj, t_ray *ray, float *t_near)
{
	float	t;

	while(*objs)
	{
		if (intersect(*objs, ray, &t) && t < *t_near)
		{
			*t_near = t;
			*hit_obj = *objs;
		}
		objs++;
	}
	if (*hit_obj != 0)
		return (1);
	return (0);
}

int	intersect(t_objs *obj, t_ray *ray, float *t)
{
	if (obj->id == SP)
		return (sphere_intersect(obj->shape, ray, t));
	if (obj->id == PL)
		return (plane_intersect(obj->shape, ray, t));
	if (obj->id == CY)
		return (cy_intersect(obj->shape, ray, t));
	if (obj->id == DI)
		return (disk_intersect(obj->shape, ray, t));
	return (0);
}

int	sol_quadratic(t_quadratic *quadratic)
{
	float	discr;
	float	q;

	discr = quadratic->b * quadratic->b - 4 * quadratic->a * quadratic->c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		quadratic->x0 = -0.5 * quadratic->b / quadratic->a;
		quadratic->x1 = -0.5 * quadratic->b / quadratic->a;
	}
	if (quadratic->b > 0)
		q = -0.5 * (quadratic->b + sqrtf(discr));
	else
		q = -0.5 * (quadratic->b - sqrtf(discr));
	quadratic->x0 = q / quadratic->a;
	quadratic->x1 = quadratic->c / q;
	return (1);
}

int	sphere_intersect(t_sphere *sphere, t_ray *ray, float *t)
{
	t_quadratic	quadratic;
	t_vec3		l;

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

int	plane_intersect(t_plane	*pl, t_ray *ray, float *t)
{
	float	tmp;

	tmp = vec3_dot(ray->direction, pl->n);
	if (tmp > 1e-6 || tmp < -1e-6)
	{
		*t = vec3_dot(vec3_minus(pl->origin, ray->origin), pl->n) / tmp;
		if (*t >= 0)
			return (1);
	}
	return (0);
}

int	disk_intersect(t_disk *disk, t_ray *ray, float *t)
{
	t_plane	pl;
	t_vec3	p;
	float	tmp;

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

int	cy_intersect(t_cylinder *cy, t_ray *ray, float *t)
{
	t_vec3	vec_o;
	t_vec3	vec_d;
	t_vec3	vec_e;
	t_quadratic	quadratic;

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

void	sphere_surface(t_objs *hit_obj, t_ray *ray, float t, t_surface *surface)
{
	t_sphere *sphere;

	sphere = hit_obj->shape;
	surface->p_hit = ray_at(t, *ray);
	surface->n_hit = vec3_unit(vec3_minus(surface->p_hit, sphere->origin));
}

void	plane_surface(t_objs *hit_obj, t_ray *ray, float t, t_surface *surface)
{
	t_plane *plane;

	plane = hit_obj->shape;
	surface->p_hit = ray_at(t, *ray);
	surface->n_hit = plane->n;
	if (vec3_dot(surface->n_hit, ray->direction) > 0)
		surface->n_hit = vec3_multi_scalar(-1, surface->n_hit);
}

void	disk_surface(t_objs *hit_obj, t_ray *ray, float t, t_surface *surface)
{
	t_disk *disk;

	disk = hit_obj->shape;
	surface->p_hit = ray_at(t, *ray);
	surface->n_hit = disk->n;
}

void	cy_surface(t_objs *hit_obj, t_ray *ray, float t, t_surface *surface)
{
	t_cylinder *cy;
	t_vec3		ep;
	t_vec3		ne;

	cy = hit_obj->shape;
	surface->p_hit = ray_at(t, *ray);
	ep = vec3_minus(surface->p_hit, cy->origin);
	ne = vec3_multi_scalar(vec3_dot(ep, cy->n), cy->n);
	surface->n_hit = vec3_unit(vec3_minus(ep, ne));
}
