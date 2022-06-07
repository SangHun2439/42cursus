/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:51:50 by bson              #+#    #+#             */
/*   Updated: 2022/05/27 19:34:46 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_next_valid(char *str, int *i)
{
	int	idx;

	idx = *i;
	if (str[idx] != ',')
		return (FALSE);
	++idx;
	++(*i);
	if (str[idx] == '-' || str[idx] == '+')
		++idx;
	if (str[idx] < '0' || str[idx] > '9')
		return (FALSE);
	return (TRUE);
}

double	parsing_one_number(char *str, int *i)
{
	int		end_idx;
	int		idx;
	double	ret;

	idx = *i;
	while (str[idx] == ' ')
		++idx;
	end_idx = idx;
	while (str[end_idx] != '\0' && !ft_strchr(" ,", str[end_idx]))
		++end_idx;
	ret = ft_atof_idx(str, &idx);
	if (end_idx != idx)
		ft_error(ERROR_WRONG_NUM);
	*i = idx;
	return (ret);
}
