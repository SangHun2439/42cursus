/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:30:25 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/25 10:48:43 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	cam_to_world_point(const t_ray *ray, t_camera *cam)
{
	t_vec3	res;

	res.e[0] = ray->origin.e[0] * cam->cam_to_world_matrix[0][0] \
	+ ray->origin.e[1] * cam->cam_to_world_matrix[1][0] \
	+ ray->origin.e[2] * cam->cam_to_world_matrix[2][0] \
	+ cam->cam_to_world_matrix[3][0];
	res.e[1] = ray->origin.e[0] * cam->cam_to_world_matrix[0][1] \
	+ ray->origin.e[1] * cam->cam_to_world_matrix[1][1] \
	+ ray->origin.e[2] * cam->cam_to_world_matrix[2][1] \
	+ cam->cam_to_world_matrix[3][1];
	res.e[2] = ray->origin.e[0] * cam->cam_to_world_matrix[0][2] \
	+ ray->origin.e[1] * cam->cam_to_world_matrix[1][2] \
	+ ray->origin.e[2] * cam->cam_to_world_matrix[2][2] \
	+ cam->cam_to_world_matrix[3][2];
	return (res);
}

t_vec3	cam_to_world_vec(const t_ray *ray, t_camera *cam)
{
	t_vec3	res;

	res.e[0] = ray->direction.e[0] * cam->cam_to_world_matrix[0][0] \
	+ ray->direction.e[1] * cam->cam_to_world_matrix[1][0] \
	+ ray->direction.e[2] * cam->cam_to_world_matrix[2][0];
	res.e[1] = ray->direction.e[0] * cam->cam_to_world_matrix[0][1] \
	+ ray->direction.e[1] * cam->cam_to_world_matrix[1][1] \
	+ ray->direction.e[2] * cam->cam_to_world_matrix[2][1];
	res.e[2] = ray->direction.e[0] * cam->cam_to_world_matrix[0][2] \
	+ ray->direction.e[1] * cam->cam_to_world_matrix[1][2] \
	+ ray->direction.e[2] * cam->cam_to_world_matrix[2][2];
	return (res);
}

t_ray	get_camera_ray(int x, int y, t_image *image, t_camera *cam)
{
	t_ray	res;

	res.origin.e[0] = 0;
	res.origin.e[1] = 0;
	res.origin.e[2] = 0;
	res.direction.e[0] = (2 * ((x + 0.5) / image->width) - 1) \
	* tan(cam->fov / 2 * M_PI / 180) * image->ratio;
	res.direction.e[1] = (1 - 2 * ((y + 0.5) / image->height)) \
	* tan(cam->fov / 2 * M_PI / 180);
	res.direction.e[2] = -1;
	res.origin = cam_to_world_point(&res, cam);
	res.direction = cam_to_world_vec(&res, cam);
	res.direction = vec3_unit(res.direction);
	return (res);
}
