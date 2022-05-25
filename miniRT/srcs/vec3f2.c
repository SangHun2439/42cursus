/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:53:14 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/25 10:26:08 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_minus(t_vec3 vec3_a, t_vec3 vec3_b)
{
	t_vec3	res;

	res.e[0] = vec3_a.e[0] - vec3_b.e[0];
	res.e[1] = vec3_a.e[1] - vec3_b.e[1];
	res.e[2] = vec3_a.e[2] - vec3_b.e[2];
	return (res);
}

t_vec3	vec3_multi(t_vec3 vec3_a, t_vec3 vec3_b)
{
	t_vec3	res;

	res.e[0] = vec3_a.e[0] * vec3_b.e[0];
	res.e[1] = vec3_a.e[1] * vec3_b.e[1];
	res.e[2] = vec3_a.e[2] * vec3_b.e[2];
	return (res);
}

t_vec3	vec3_multi_scalar(float t, t_vec3 vec3_a)
{
	t_vec3	res;

	res.e[0] = vec3_a.e[0] * t;
	res.e[1] = vec3_a.e[1] * t;
	res.e[2] = vec3_a.e[2] * t;
	return (res);
}

t_vec3	vec3_div(float t, t_vec3 vec3_a)
{
	t_vec3	res;

	res.e[0] = vec3_a.e[0] * (1 / t);
	res.e[1] = vec3_a.e[1] * (1 / t);
	res.e[2] = vec3_a.e[2] * (1 / t);
	return (res);
}

float	vec3_dot(t_vec3 vec3_a, t_vec3 vec3_b)
{
	return ((vec3_a.e[0] * vec3_b.e[0]) + \
	(vec3_a.e[1] * vec3_b.e[1]) + (vec3_a.e[2] * vec3_b.e[2]));
}
