/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:30:05 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/25 09:59:52 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>
# include <stdlib.h>

typedef struct s_vec3
{
	float	e[3];
}	t_vec3;

float	vec3_len_squared(t_vec3 vec3_a);
float	vec3_len(t_vec3 vec3_a);
t_vec3	vec3_unit(t_vec3 vec3_a);
t_vec3	vec3_plus(t_vec3 vec3_a, t_vec3 vec3_b);
t_vec3	vec3_minus(t_vec3 vec3_a, t_vec3 vec3_b);
t_vec3	vec3_multi(t_vec3 vec3_a, t_vec3 vec3_b);
t_vec3	vec3_multi_scalar(float t, t_vec3 vec3_a);
t_vec3	vec3_div(float t, t_vec3 vec3_a);
float	vec3_dot(t_vec3 vec3_a, t_vec3 vec3_b);
t_vec3	vec3_cross(t_vec3 vec3_a, t_vec3 vec3_b);
t_vec3	get_vec3_same_val(float a);
t_vec3	vec3_set(float x, float y, float z);

#endif
