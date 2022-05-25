/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:38:59 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/25 10:22:18 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	image_init(t_image **image)
{
	int	idx;

	(*image) = malloc(sizeof(t_image));
	if ((*image) == NULL)
		exit(1);
	(*image)->width = IMAGE_WIDTH;
	(*image)->height = IMAGE_HEIGHT;
	(*image)->ratio = (float)(*image)->width / (float)(*image)->height;
	(*image)->pixel = malloc(sizeof(t_vec3 *) * ((*image)->height));
	if ((*image)->pixel == NULL)
		exit(1);
	idx = 0;
	while (idx < (*image)->height)
	{
		(*image)->pixel[idx] = malloc(sizeof(t_vec3) * (*image)->width);
		if ((*image)->pixel[idx] == NULL)
			exit(1);
		idx++;
	}
}

void	set_cam_to_world_matrix(t_camera *camera)
{
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;

	forward = vec3_multi_scalar(-1, camera->ori);
	right = vec3_cross(vec3_set(0, 1, 0), forward);
	if (vec3_len(right) < 1e-6)
		right = vec3_cross(vec3_set(0, 0, 1), forward);
	up = vec3_cross(forward, right);
	camera->cam_to_world_matrix[0][0] = right.e[0];
	camera->cam_to_world_matrix[0][1] = right.e[1];
	camera->cam_to_world_matrix[0][2] = right.e[2];
	camera->cam_to_world_matrix[1][0] = up.e[0];
	camera->cam_to_world_matrix[1][1] = up.e[1];
	camera->cam_to_world_matrix[1][2] = up.e[2];
	camera->cam_to_world_matrix[2][0] = forward.e[0];
	camera->cam_to_world_matrix[2][1] = forward.e[1];
	camera->cam_to_world_matrix[2][2] = forward.e[2];
	camera->cam_to_world_matrix[3][0] = camera->point.e[0];
	camera->cam_to_world_matrix[3][1] = camera->point.e[1];
	camera->cam_to_world_matrix[3][2] = camera->point.e[2];
}

void	camera_init(t_camera **camera, char **element)
{
	char	**tmp;

	*camera = malloc(sizeof(t_camera));
	tmp = ft_split(element[1], ',');
	(*camera)->point.e[0] = ft_atof(tmp[0]);
	(*camera)->point.e[1] = ft_atof(tmp[1]);
	(*camera)->point.e[2] = ft_atof(tmp[2]);
	free_split(tmp);
	tmp = ft_split(element[2], ',');
	(*camera)->ori.e[0] = ft_atof(tmp[0]);
	(*camera)->ori.e[1] = ft_atof(tmp[1]);
	(*camera)->ori.e[2] = ft_atof(tmp[2]);
	free_split(tmp);
	(*camera)->ori = vec3_unit((*camera)->ori);
	(*camera)->fov = ft_atoi(element[3]);
	set_cam_to_world_matrix(*camera);
}

void	read_file_init2(char **element, t_camera **cam, \
t_list **objs, t_list **lights)
{
	if (!ft_strncmp(element[0], "C", 1))
		camera_init(cam, element);
	else if (!ft_strncmp(element[0], "L", 1))
		light_init(lights, element);
	else if (!ft_strncmp(element[0], "A", 1))
		ambient_init(lights, element);
	else if (!ft_strncmp(element[0], "sp", 2))
		sp_pl_obj_init(objs, element, SP);
	else if (!ft_strncmp(element[0], "pl", 2))
		sp_pl_obj_init(objs, element, PL);
	else if (!ft_strncmp(element[0], "cy", 2))
		cy_obj_init(objs, element);
}

void	read_file_init(char *file_name, t_camera **cam, \
t_list **objs, t_list **lights)
{
	int		fd;
	char	*str;
	char	**element;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(0);
	while (get_next_line(fd, &str))
	{
		element = ft_split(str, ' ');
		read_file_init2(element, cam, objs, lights);
		free_split(element);
		free(str);
	}
	free(str);
	close(fd);
}
