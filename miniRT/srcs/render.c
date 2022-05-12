/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:20:15 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/12 10:22:41 by sangjeon         ###   ########.fr       */
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

t_vec3	ray_color(t_ray *ray, t_objs **objs)
{
	t_vec3	res;
	t_objs	*hit_obj;
	float	t_near;

	hit_obj = 0;
	t_near = INFINITY;
	if (trace(objs, &hit_obj, ray, &t_near))
	{
		return (hit_obj->rgb);
	}
	else
	{
		res.e[0] = 0.2;
		res.e[1] = 0.2;
		res.e[2] = 0.2;
	}
	return (res);
}

void	render(t_image *image, t_camera *cam, t_objs **objs)
{
	t_ray	camera_ray;

	for (int j = 0; j < image->height; ++j)
	{
		for (int i = 0; i < image->width; ++i)
		{
			camera_ray = get_camera_ray(i, j, image, cam);
			// printf("Ray<%d> -- position : (%lf, %lf, %lf) direction : (%lf, %lf, %lf)\n", j * image->width + i, camera_ray.origin.e[0], camera_ray.origin.e[1], camera_ray.origin.e[2], camera_ray.direction.e[0], camera_ray.direction.e[1], camera_ray.direction.e[2]);
			image->pixel[j][i] = ray_color(&camera_ray, objs);
		}
	}
}
