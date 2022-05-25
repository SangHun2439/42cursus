/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:15:13 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/25 10:25:26 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ambient_init(t_list **lights, char **element)
{
	t_light	*ambient;
	t_list	*list_ele;
	char	**tmp;

	ambient = malloc(sizeof(t_light));
	if (!ambient)
		exit(1);
	ambient->id = A;
	ambient->bright = ft_atof(element[1]);
	tmp = ft_split(element[2], ',');
	ambient->rgb.e[0] = ft_atof(tmp[0]) / RGB_MAX;
	ambient->rgb.e[1] = ft_atof(tmp[1]) / RGB_MAX;
	ambient->rgb.e[2] = ft_atof(tmp[2]) / RGB_MAX;
	free_split(tmp);
	list_ele = ft_lstnew(ambient);
	if (!list_ele)
		exit(1);
	ft_lstadd_front(lights, list_ele);
}

void	light_init(t_list **lights, char **element)
{
	t_light	*light;
	t_list	*list_ele;
	char	**tmp;

	light = malloc(sizeof(t_light));
	if (!light)
		exit(1);
	light->id = L;
	tmp = ft_split(element[1], ',');
	light->origin.e[0] = ft_atof(tmp[0]);
	light->origin.e[1] = ft_atof(tmp[1]);
	light->origin.e[2] = ft_atof(tmp[2]);
	free_split(tmp);
	light->bright = ft_atof(element[2]);
	tmp = ft_split(element[3], ',');
	light->rgb.e[0] = ft_atof(tmp[0]) / RGB_MAX;
	light->rgb.e[1] = ft_atof(tmp[1]) / RGB_MAX;
	light->rgb.e[2] = ft_atof(tmp[2]) / RGB_MAX;
	free_split(tmp);
	list_ele = ft_lstnew(light);
	if (!list_ele)
		exit(1);
	ft_lstadd_front(lights, list_ele);
}

void	sp_pl_obj_init(t_list **objs, char **element, int id)
{
	t_objs	*obj;
	t_list	*list_ele;
	char	**tmp;

	obj = malloc(sizeof(t_objs));
	if (!obj)
		exit(1);
	obj->id = id;
	tmp = ft_split(element[3], ',');
	obj->rgb.e[0] = ft_atof(tmp[0]) / RGB_MAX;
	obj->rgb.e[1] = ft_atof(tmp[1]) / RGB_MAX;
	obj->rgb.e[2] = ft_atof(tmp[2]) / RGB_MAX;
	free_split(tmp);
	if (id == SP)
		sp_init(obj, element);
	if (id == PL)
		pl_init(obj, element);
	list_ele = ft_lstnew(obj);
	if (!list_ele)
		exit(1);
	ft_lstadd_front(objs, list_ele);
}

void	sp_init(t_objs *obj, char **element)
{
	t_sphere	*sphere;
	char		**tmp;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		exit(1);
	obj->shape = sphere;
	tmp = ft_split(element[1], ',');
	sphere->origin.e[0] = ft_atof(tmp[0]);
	sphere->origin.e[1] = ft_atof(tmp[1]);
	sphere->origin.e[2] = ft_atof(tmp[2]);
	free_split(tmp);
	sphere->r = ft_atof(element[2]) / 2.0f;
	obj->intersect = sphere_intersect;
	obj->surface = sphere_surface;
}

void	pl_init(t_objs *obj, char **element)
{
	t_plane	*plane;
	char	**tmp;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		exit(1);
	obj->shape = plane;
	tmp = ft_split(element[1], ',');
	plane->origin.e[0] = ft_atof(tmp[0]);
	plane->origin.e[1] = ft_atof(tmp[1]);
	plane->origin.e[2] = ft_atof(tmp[2]);
	free_split(tmp);
	tmp = ft_split(element[2], ',');
	plane->n.e[0] = ft_atof(tmp[0]);
	plane->n.e[1] = ft_atof(tmp[1]);
	plane->n.e[2] = ft_atof(tmp[2]);
	free_split(tmp);
	plane->n = vec3_unit(plane->n);
	obj->intersect = plane_intersect;
	obj->surface = plane_surface;
}
