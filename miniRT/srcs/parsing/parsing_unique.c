/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_unique.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:51:44 by bson              #+#    #+#             */
/*   Updated: 2022/05/27 19:10:51 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parsing_ambient(t_minirt *minirt, char *str, int i)
{
	t_light	*ambient;
	t_list	*list_ele;

	if (minirt->unique[UNIQUE_AMBIENT])
		ft_error(ERROR_UNIQUE);
	if (check_line(str, i, ALLOW_CHAR_SET) == FALSE)
		ft_error(ERROR_INVALID_CHAR);
	ambient = ft_calloc_assert(1, sizeof(t_light));
	ambient->id = A;
	ambient->bright = parsing_one_number(str, &i);
	if (check_range(ambient->bright, 0, 1) == FALSE)
		ft_error(ERROR_OUT_OF_RANGE);
	parsing_color(&ambient->rgb, str, &i);
	if (is_empty(str + i) == FALSE)
		ft_error(ERROR_WRONG_DATA);
	minirt->unique[UNIQUE_AMBIENT] = 1;
	list_ele = ft_lstnew(ambient);
	if (!list_ele)
		exit(1);
	ft_lstadd_front(&minirt->lights, list_ele);
}

void	parsing_camera(t_minirt *minirt, char *str, int i)
{
	if (minirt->unique[UNIQUE_CAMERA])
		ft_error(ERROR_UNIQUE);
	if (check_line(str, i, ALLOW_CHAR_SET) == FALSE)
		ft_error(ERROR_INVALID_CHAR);
	minirt->cam = (t_camera *)ft_calloc_assert(1, sizeof(t_camera));
	parsing_position(&minirt->cam->point, str, &i);
	parsing_normal(&minirt->cam->ori, str, &i);
	minirt->cam->fov = parsing_one_number(str, &i);
	if (check_range(minirt->cam->fov, 0, 180) == FALSE)
		ft_error(ERROR_OUT_OF_RANGE);
	if (is_empty(str + i) == FALSE)
		ft_error(ERROR_WRONG_DATA);
	minirt->unique[UNIQUE_CAMERA] = 1;
	set_cam_to_world_matrix(minirt->cam);
}

void	parsing_light(t_minirt *minirt, char *str, int i)
{
	t_light	*light;
	t_list	*list_ele;

	if (check_line(str, i, ALLOW_CHAR_SET) == FALSE)
		ft_error(ERROR_INVALID_CHAR);
	light = (t_light *)ft_calloc_assert(1, sizeof(t_light));
	light->id = L;
	parsing_position(&light->origin, str, &i);
	light->bright = parsing_one_number(str, &i);
	if (check_range(light->bright, 0, 1) == FALSE)
		ft_error(ERROR_OUT_OF_RANGE);
	if (is_empty(str + i) == FALSE)
		parsing_color(&light->rgb, str, &i);
	else
		light->rgb = vec3_set(1, 1, 1);
	if (is_empty(str + i) == FALSE)
		ft_error(ERROR_WRONG_DATA);
	list_ele = ft_lstnew(light);
	if (!list_ele)
		exit(1);
	ft_lstadd_front(&minirt->lights, list_ele);
}
