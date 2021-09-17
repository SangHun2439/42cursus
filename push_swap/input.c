/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:14:54 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/17 09:54:48 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_free(char **strarr)
{
	char	**tmp;

	tmp = strarr;
	while (*tmp)
		free(*tmp++);
	free(strarr);
}

static void	arr_input(char **strarr, t_deque *a_deq, int *p_err)
{
	char	**tmp;
	int		*content;

	tmp = strarr;
	while (*tmp)
	{
		content = (int *)malloc(sizeof(int));
		*content = errcheck_atoi(*tmp, p_err);
		if (*p_err)
		{
			split_free(strarr);
			free(content);
			return ;
		}
		ft_deqadd_back(a_deq, content);
		tmp++;
	}
}

void	input(int argc, char **argv, t_deque *a_deq, int *p_err)
{
	int		idx;
	char	**strarr;

	idx = 1;
	while (idx < argc)
	{
		strarr = ft_split(argv[idx], ' ');
		if (!strarr || !*strarr)
		{
			*p_err = 1;
			return ;
		}
		arr_input(strarr, a_deq, p_err);
		if (*p_err)
			return ;
		split_free(strarr);
		idx++;
	}
}
