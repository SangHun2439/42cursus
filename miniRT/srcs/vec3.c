/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:16:21 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/11 18:09:18 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

float	vec3_len_squared(t_vec3 vec3_a)
{
	return ((vec3_a.e[0] * vec3_a.e[0]) + (vec3_a.e[1] * vec3_a.e[1]) + (vec3_a.e[2] * vec3_a.e[2]));
}

float	vec3_len(t_vec3 vec3_a)
{
	return (sqrtf(vec3_len_squared(vec3_a)));
}

t_vec3	vec3_unit(t_vec3 vec3_a)
{
	t_vec3	res;
	float	len;

	len = vec3_len(vec3_a);
	res.e[0] = vec3_a.e[0] / len;
	res.e[1] = vec3_a.e[1] / len;
	res.e[2] = vec3_a.e[2] / len;
	return (res);
}

t_vec3	vec3_plus(t_vec3 vec3_a, t_vec3 vec3_b)
{
	t_vec3	res;

	res.e[0] = vec3_a.e[0] + vec3_b.e[0];
	res.e[1] = vec3_a.e[1] + vec3_b.e[1];
	res.e[2] = vec3_a.e[2] + vec3_b.e[2];
	return (res);
}

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

	res.e[0] = vec3_a.e[0] * (1/t);
	res.e[1] = vec3_a.e[1] * (1/t);
	res.e[2] = vec3_a.e[2] * (1/t);
	return (res);
}

float	vec3_dot(t_vec3 vec3_a, t_vec3 vec3_b)
{
	return ((vec3_a.e[0] * vec3_b.e[0]) + (vec3_a.e[1] * vec3_b.e[1]) + (vec3_a.e[2] * vec3_b.e[2]));
}

t_vec3	vec3_cross(t_vec3 vec3_a, t_vec3 vec3_b)
{
	t_vec3	res;

	res.e[0] = vec3_a.e[1] * vec3_b.e[2] - vec3_a.e[2] * vec3_b.e[1];
	res.e[1] = vec3_a.e[2] * vec3_b.e[0] - vec3_a.e[0] * vec3_b.e[2];
	res.e[2] = vec3_a.e[0] * vec3_b.e[1] - vec3_a.e[1] * vec3_b.e[0];
	return (res);
}
