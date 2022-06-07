/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:05:09 by bson              #+#    #+#             */
/*   Updated: 2022/06/02 13:20:56 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_objs.h"
#include "obj_viewer.h"

void	view_minirt(t_minirt *rt)
{
	draw_big_border();
	view_camera(rt->cam, 0);
	draw_big_border();
	view_list_objs("objs", rt->objs);
	draw_big_border();
	view_list_light("lights", rt->lights);
	draw_big_border();
}
