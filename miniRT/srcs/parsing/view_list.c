/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:05:17 by bson              #+#    #+#             */
/*   Updated: 2022/06/02 14:14:46 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_objs.h"
#include "obj_viewer.h"

void	draw_big_border(void)
{
	printf("==============================\n");
}

void	draw_small_border(void)
{
	printf("-------------------------\n");
}

void	view_list_objs(char *name, t_list *list)
{
	t_list	*iter;
	t_objs	*content;

	iter = list;
	printf("%s list\n", name);
	while (iter)
	{
		content = iter->content;
		if (content->id == 1)
			view_sphere((t_sphere *)content->shape, 1);
		else if (content->id == 2)
			view_plane((t_plane *)content->shape, 1);
		else if (content->id == 3)
			view_cylinder((t_cylinder *)content->shape, 1);
		else if (content->id == 4)
			view_disk((t_disk *)content->shape, 1);
		view_vec3("rgb", content->rgb, 1);
		draw_small_border();
		iter = iter->next;
	}
}

void	view_list_light(char *name, t_list *list)
{
	t_list	*iter;
	t_light	*content;

	iter = list;
	printf("%s list\n", name);
	while (iter)
	{
		content = iter->content;
		view_light(content, 1);
		draw_small_border();
		iter = iter->next;
	}
}

void	view_disk(t_disk *d, int deps)
{
	print_deps(deps);
	printf("Disk :\n");
	view_vec3("origin", d->origin, deps + 1);
	view_vec3("n", d->n, deps + 1);
}
