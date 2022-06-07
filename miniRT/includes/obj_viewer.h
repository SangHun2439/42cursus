/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_viewer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:05:33 by bson              #+#    #+#             */
/*   Updated: 2022/06/02 13:20:48 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_VIEWER_H
# define OBJ_VIEWER_H

# include <stdio.h>
# include "minirt_objs.h"

void	view_vec3(char *name, t_vec3 v, int deps);
void	view_matrix_44(char *name, float m[4][4], int deps);
void	draw_big_border(void);
void	draw_small_border(void);
void	view_f(char *name, float f, int deps);
void	view_i(char *name, int i, int deps);
void	view_camera(t_camera *c, int deps);
void	view_sphere(t_sphere *sp, int deps);
void	view_plane(t_plane *pl, int deps);
void	view_cylinder(t_cylinder *cy, int deps);
void	view_light(t_light *l, int deps);
void	view_disk(t_disk *d, int deps);
void	view_list_light(char *name, t_list *list);
void	view_list_objs(char *name, t_list *list);
void	view_minirt(t_minirt *rt);
void	print_deps(int i);

#endif
