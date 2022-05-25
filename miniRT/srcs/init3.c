/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:13:27 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/25 10:30:54 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cy_obj_init(t_list **objs, char **element)
{
	t_objs	*obj;
	t_list	*list_ele;
	char	**tmp;

	obj = malloc(sizeof(t_objs));
	if (!obj)
		exit(1);
	tmp = ft_split(element[5], ',');
	obj->rgb.e[0] = ft_atof(tmp[0]) / RGB_MAX;
	obj->rgb.e[1] = ft_atof(tmp[1]) / RGB_MAX;
	obj->rgb.e[2] = ft_atof(tmp[2]) / RGB_MAX;
	free_split(tmp);
	obj->id = CY;
	cy_init(obj, element);
	list_ele = ft_lstnew(obj);
	if (!list_ele)
		exit(1);
	ft_lstadd_front(objs, list_ele);
	disk_obj_init(objs, obj, UP);
	disk_obj_init(objs, obj, DOWN);
}

void	disk_obj_init(t_list **objs, const t_objs *for_cp, int direction)
{
	t_objs	*obj_disk;
	t_list	*list_ele;

	obj_disk = malloc(sizeof(t_objs));
	if (!obj_disk)
		exit(1);
	obj_disk->id = DI;
	obj_disk->rgb = for_cp->rgb;
	disk_init(obj_disk, for_cp, direction);
	list_ele = ft_lstnew(obj_disk);
	if (!list_ele)
		exit(1);
	ft_lstadd_front(objs, list_ele);
}

void	disk_init(t_objs *obj_disk, const t_objs *for_cp, int direction)
{
	t_disk				*disk;
	const t_cylinder	*cy_for_cp;

	disk = malloc(sizeof(t_disk));
	if (!disk)
		exit(1);
	cy_for_cp = for_cp->shape;
	obj_disk->shape = disk;
	disk->r = cy_for_cp->r;
	if (direction == UP)
	{
		disk->n = cy_for_cp->n;
		disk->origin = vec3_plus(cy_for_cp->origin, \
		vec3_multi_scalar(cy_for_cp->h, cy_for_cp->n));
	}
	else if (direction == DOWN)
	{
		disk->n = vec3_multi_scalar(-1, cy_for_cp->n);
		disk->origin = cy_for_cp->origin;
	}
	obj_disk->intersect = disk_intersect;
	obj_disk->surface = disk_surface;
}

void	cy_init(t_objs *obj, char **element)
{
	t_cylinder	*cy;
	char		**tmp;

	cy = malloc(sizeof(t_cylinder));
	if (!cy)
		exit(1);
	obj->shape = cy;
	tmp = ft_split(element[1], ',');
	cy->origin.e[0] = ft_atof(tmp[0]);
	cy->origin.e[1] = ft_atof(tmp[1]);
	cy->origin.e[2] = ft_atof(tmp[2]);
	free_split(tmp);
	tmp = ft_split(element[2], ',');
	cy->n.e[0] = ft_atof(tmp[0]);
	cy->n.e[1] = ft_atof(tmp[1]);
	cy->n.e[2] = ft_atof(tmp[2]);
	free_split(tmp);
	cy->n = vec3_unit(cy->n);
	cy->r = ft_atof(element[3]) / 2.0f;
	cy->h = ft_atof(element[4]);
	obj->intersect = cy_intersect;
	obj->surface = cy_surface;
}

void	rt_init(t_minirt *rt, char *file_name)
{
	rt->file_name = file_name;
	rt->mlx = malloc(sizeof(t_mlx));
	if (!(rt->mlx))
		exit(0);
	rt->mlx->mlx_ptr = mlx_init();
	rt->mlx->win = mlx_new_window(rt->mlx->mlx_ptr, \
	rt->image->width, rt->image->height, "miniRT");
	rt->mlx->mlx_image = mlx_new_image(rt->mlx->mlx_ptr, \
	rt->image->width, rt->image->height);
	rt->mlx->pb = 32;
	rt->mlx->lb = 4 * rt->image->width;
	rt->mlx->mlx_pixel = (int *)mlx_get_data_addr(rt->mlx->mlx_image, \
	&(rt->mlx->pb), &(rt->mlx->lb), &(rt->mlx->endian));
	rt->mlx->lb /= 4;
}
