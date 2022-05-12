/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:51:20 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/09 10:29:38 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "minirt_objs.h"

void	print_image(t_image *image)
{
	printf("P3\n%d %d\n255\n", image->width, image->height);

	for (int j = 0; j < image->height; ++j)
	{
		for (int i = 0; i < image->width; ++i)
		{
			int ir = (int)(255.999 * image->pixel[j][i].e[0]);
			int ig = (int)(255.999 * image->pixel[j][i].e[1]);
			int ib = (int)(255.999 * image->pixel[j][i].e[2]);

			printf("%d %d %d\n", ir, ig, ib);
		}
	}
}
