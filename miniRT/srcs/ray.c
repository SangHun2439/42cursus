/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:15 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/11 15:50:41 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_vec3	ray_at(float t, t_ray ray)
{
	t_vec3	res;

	res.e[0] = ray.origin.e[0] + ray.direction.e[0] * t;
	res.e[1] = ray.origin.e[1] + ray.direction.e[1] * t;
	res.e[2] = ray.origin.e[2] + ray.direction.e[2] * t;
	return (res);
}
