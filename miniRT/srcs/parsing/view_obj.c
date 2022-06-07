/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:05:06 by bson              #+#    #+#             */
/*   Updated: 2022/06/02 13:21:19 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_viewer.h"

void	view_camera(t_camera *c, int deps)
{
	print_deps(deps);
	printf("Camera :\n");
	view_vec3("point", c->point, deps + 1);
	view_vec3("ori", c->ori, deps + 1);
	view_i("fov", c->fov, deps + 1);
	view_matrix_44("cam_to_world_matrix", c->cam_to_world_matrix, deps + 1);
}

void	view_sphere(t_sphere *sp, int deps)
{
	print_deps(deps);
	printf("Sphere :\n");
	view_vec3("origin", sp->origin, deps + 1);
	view_f("r", sp->r, deps + 1);
}

void	view_plane(t_plane *pl, int deps)
{
	print_deps(deps);
	printf("Plane :\n");
	view_vec3("origin", pl->origin, deps + 1);
	view_vec3("n", pl->n, deps + 1);
}

void	view_cylinder(t_cylinder *cy, int deps)
{
	print_deps(deps);
	printf("Cylinder :\n");
	view_vec3("origin", cy->origin, deps + 1);
	view_vec3("n", cy->n, deps + 1);
	view_f("r", cy->r, deps + 1);
	view_f("h", cy->h, deps + 1);
}

void	view_light(t_light *l, int deps)
{
	print_deps(deps);
	if (l->id == 1)
		printf("Ambient :\n");
	else
		printf("Light :\n");
	view_vec3("origin", l->origin, deps + 1);
	view_vec3("rgb", l->rgb, deps + 1);
	view_f("bright", l->bright, deps + 1);
}
