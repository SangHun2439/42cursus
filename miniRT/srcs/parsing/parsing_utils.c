/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:51:47 by bson              #+#    #+#             */
/*   Updated: 2022/05/27 14:04:04 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_empty(char *line)
{
	int	idx;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] != ' ')
			return (FALSE);
		++idx;
	}
	return (TRUE);
}

t_bool	check_line(char *line, int i, char *set)
{
	while (line[i])
	{
		if (ft_strchr(set, line[i]) == NULL)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

void	parsing_color(t_vec3 *color, char *str, int *i)
{
	int	idx;

	idx = *i;
	color->e[0] = parsing_one_number(str, &idx);
	if (check_range(color->e[0], 0, 255) == FALSE)
		ft_error(ERROR_OUT_OF_RANGE);
	if (is_next_valid(str, &idx) == FALSE)
		ft_error(ERROR_RGB_FORMAT);
	color->e[1] = parsing_one_number(str, &idx);
	if (check_range(color->e[1], 0, 255) == FALSE)
		ft_error(ERROR_OUT_OF_RANGE);
	if (is_next_valid(str, &idx) == FALSE)
		ft_error(ERROR_RGB_FORMAT);
	color->e[2] = parsing_one_number(str, &idx);
	if (check_range(color->e[2], 0, 255) == FALSE)
		ft_error(ERROR_OUT_OF_RANGE);
	*color = vec3_div(RGB_MAX, *color);
	*i = idx;
}

void	parsing_position(t_vec3 *pos, char *str, int *i)
{
	int	idx;

	idx = *i;
	pos->e[0] = parsing_one_number(str, &idx);
	if (is_next_valid(str, &idx) == FALSE)
		ft_error(ERROR_VEC_FORMAT);
	pos->e[1] = parsing_one_number(str, &idx);
	if (is_next_valid(str, &idx) == FALSE)
		ft_error(ERROR_VEC_FORMAT);
	pos->e[2] = parsing_one_number(str, &idx);
	*i = idx;
}

void	parsing_normal(t_vec3 *n, char *str, int *i)
{
	int	idx;

	idx = *i;
	n->e[0] = parsing_one_number(str, &idx);
	if (check_range(n->e[0], -1, 1) == FALSE)
		ft_error(ERROR_OUT_OF_RANGE);
	if (is_next_valid(str, &idx) == FALSE)
		ft_error(ERROR_VEC_FORMAT);
	n->e[1] = parsing_one_number(str, &idx);
	if (check_range(n->e[1], -1, 1) == FALSE)
		ft_error(ERROR_OUT_OF_RANGE);
	if (is_next_valid(str, &idx) == FALSE)
		ft_error(ERROR_VEC_FORMAT);
	n->e[2] = parsing_one_number(str, &idx);
	if (check_range(n->e[2], -1, 1) == FALSE)
		ft_error(ERROR_OUT_OF_RANGE);
	*n = vec3_unit(*n);
	*i = idx;
}
