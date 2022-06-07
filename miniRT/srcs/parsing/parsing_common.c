/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_common.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:51:41 by bson              #+#    #+#             */
/*   Updated: 2022/05/27 13:36:49 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parsing_sphere(t_minirt *minirt, char *str, int i)
{
	t_sphere	*sphere;
	t_objs		*obj;
	t_list		*list_ele;

	if (check_line(str, i, ALLOW_CHAR_SET) == FALSE)
		ft_error(ERROR_INVALID_CHAR);
	sphere = (t_sphere *)ft_calloc_assert(1, sizeof(t_sphere));
	parsing_position(&sphere->origin, str, &i);
	sphere->r = parsing_one_number(str, &i) / 2.0f;
	if (sphere->r <= 0)
		ft_error(ERROR_OUT_OF_RANGE);
	obj = (t_objs *)ft_calloc_assert(1, sizeof(t_objs));
	obj->shape = sphere;
	obj->id = SP;
	parsing_color(&obj->rgb, str, &i);
	if (is_empty(str + i) == FALSE)
		ft_error(ERROR_WRONG_DATA);
	obj->intersect = sphere_intersect;
	obj->surface = sphere_surface;
	list_ele = ft_lstnew(obj);
	if (!list_ele)
		exit(1);
	ft_lstadd_front(&minirt->objs, list_ele);
}

void	parsing_plane(t_minirt *minirt, char *str, int i)
{
	t_plane		*plane;
	t_objs		*obj;
	t_list		*list_ele;

	if (check_line(str, i, ALLOW_CHAR_SET) == FALSE)
		ft_error(ERROR_INVALID_CHAR);
	plane = (t_plane *)ft_calloc_assert(1, sizeof(t_plane));
	parsing_position(&plane->origin, str, &i);
	parsing_normal(&plane->n, str, &i);
	obj = (t_objs *)ft_calloc_assert(1, sizeof(t_objs));
	obj->shape = plane;
	obj->id = PL;
	parsing_color(&obj->rgb, str, &i);
	if (is_empty(str + i) == FALSE)
		ft_error(ERROR_WRONG_DATA);
	obj->intersect = plane_intersect;
	obj->surface = plane_surface;
	list_ele = ft_lstnew(obj);
	if (!list_ele)
		exit(1);
	ft_lstadd_front(&minirt->objs, list_ele);
}

void	parsing_cylinder(t_minirt *minirt, char *str, int i)
{
	t_cylinder	*cylinder;
	t_objs		*obj;
	t_list		*list_ele;

	if (check_line(str, i, ALLOW_CHAR_SET) == FALSE)
		ft_error(ERROR_INVALID_CHAR);
	cylinder = (t_cylinder *)ft_calloc_assert(1, sizeof(t_cylinder));
	parsing_position(&cylinder->origin, str, &i);
	parsing_normal(&cylinder->n, str, &i);
	cylinder->r = parsing_one_number(str, &i) / 2.0f;
	cylinder->h = parsing_one_number(str, &i);
	obj = (t_objs *)ft_calloc_assert(1, sizeof(t_objs));
	obj->shape = cylinder;
	parsing_color(&obj->rgb, str, &i);
	if (is_empty(str + i) == FALSE)
		ft_error(ERROR_WRONG_DATA);
	obj->id = CY;
	obj->intersect = cy_intersect;
	obj->surface = cy_surface;
	list_ele = ft_lstnew(obj);
	if (!list_ele)
		exit(1);
	ft_lstadd_front(&minirt->objs, list_ele);
	disk_obj_init(&minirt->objs, obj, UP);
	disk_obj_init(&minirt->objs, obj, DOWN);
}
