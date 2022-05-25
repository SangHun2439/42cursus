/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:37:21 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/25 10:29:31 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_split(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
		free(str_arr[i++]);
	free(str_arr);
}

void	free_image(t_image *image)
{
	int	idx;

	idx = 0;
	while (idx < image->height)
		free(image->pixel[idx++]);
	free(image->pixel);
	free(image);
}

void	free_objs(void *objs)
{
	t_objs	*obj;

	obj = objs;
	free(obj->shape);
	free(obj);
}

void	all_free(t_image *image, t_camera *cam, t_list *objs, t_list *lights)
{
	free_image(image);
	free(cam);
	ft_lstclear(&objs, free_objs);
	ft_lstclear(&lights, free);
}

int	sol_quadratic(t_quadratic *quadratic)
{
	float	discr;
	float	q;

	discr = quadratic->b * quadratic->b - 4 * quadratic->a * quadratic->c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		quadratic->x0 = -0.5 * quadratic->b / quadratic->a;
		quadratic->x1 = -0.5 * quadratic->b / quadratic->a;
	}
	if (quadratic->b > 0)
		q = -0.5 * (quadratic->b + sqrtf(discr));
	else
		q = -0.5 * (quadratic->b - sqrtf(discr));
	quadratic->x0 = q / quadratic->a;
	quadratic->x1 = quadratic->c / q;
	return (1);
}
