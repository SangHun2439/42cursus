/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:45:13 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/25 11:02:28 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	convert_rgb(t_vec3 rgb)
{
	int	ir;
	int	ig;
	int	ib;

	ir = (int)(255.999 * rgb.e[0]);
	ig = (int)(255.999 * rgb.e[1]);
	ib = (int)(255.999 * rgb.e[2]);
	return ((ir << 16) + (ig << 8) + ib);
}

void	swap_float(float *a, float *b)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
