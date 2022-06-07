/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_vec3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:05:02 by bson              #+#    #+#             */
/*   Updated: 2022/06/02 14:18:48 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_viewer.h"
#include "minirt_objs.h"

void	print_deps(int i)
{
	while (i > 0)
	{
		printf("\t");
		--i;
	}
}

void	view_vec3(char *name, t_vec3 v, int deps)
{
	print_deps(deps);
	printf("%s : \n", name);
	print_deps(deps + 1);
	printf("{%.3f | %.3f | %.3f}\n", v.e[0], v.e[1], v.e[2]);
}

void	view_i(char *name, int i, int deps)
{
	print_deps(deps);
	printf("%s : %d\n", name, i);
}

void	view_f(char *name, float f, int deps)
{
	print_deps(deps);
	printf("%s : %.3f\n", name, f);
}

void	view_matrix_44(char *name, float m[4][4], int deps)
{
	int	i;
	int	j;

	print_deps(deps);
	printf("%s : \n", name);
	print_deps(deps + 1);
	i = 0;
	while (i < 4)
	{
		printf("{");
		j = 0;
		while (j < 4)
		{
			printf("%.3f", m[i][j]);
			if (j != 3)
				printf(", ");
			++j;
		}
		printf("}\n");
		print_deps(deps + 1);
		++i;
	}
	printf("\n");
}
