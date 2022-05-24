/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:54:00 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/24 18:54:13 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_cross(t_vec3 vec3_a, t_vec3 vec3_b)
{
	t_vec3	res;

	res.e[0] = vec3_a.e[1] * vec3_b.e[2] - vec3_a.e[2] * vec3_b.e[1];
	res.e[1] = vec3_a.e[2] * vec3_b.e[0] - vec3_a.e[0] * vec3_b.e[2];
	res.e[2] = vec3_a.e[0] * vec3_b.e[1] - vec3_a.e[1] * vec3_b.e[0];
	return (res);
}
