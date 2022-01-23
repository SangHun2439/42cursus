/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:40:46 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:36 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cnt_cmd(const char *cmd)
{
	int	cnt;
	int	quote_flag;

	cnt = 1;
	quote_flag = 0;
	while (*cmd)
	{
		if (!quote_flag)
			quote_flag = is_quote(*cmd);
		else if (quote_flag == is_quote(*cmd))
			quote_flag = 0;
		if (!quote_flag && is_sep(*cmd))
			cnt++;
		cmd++;
	}
	return (cnt);
}

void	quote_check(int *flag_ptr, char c)
{
	if (!*flag_ptr)
		*flag_ptr = is_quote(c);
	else if (*flag_ptr == is_quote(c))
		*flag_ptr = 0;
}

int	do_split_cmd(char **res, char *cmd, int cnt)
{
	char	*tmp;
	int		quote_flag;
	int		idx;

	idx = 0;
	quote_flag = 0;
	tmp = cmd;
	while (*cmd)
	{
		quote_check(&quote_flag, *cmd);
		if (!quote_flag && is_sep(*cmd))
		{
			res[idx] = ft_strndup(tmp, cmd - tmp);
			if (!res[idx])
				return (0);
			tmp = cmd + 1;
			idx++;
		}
		cmd++;
	}
	res[idx] = ft_strndup(tmp, cmd - tmp);
	if (!res[idx])
		return (0);
	res[cnt] = 0;
	return (1);
}

char	**split_cmd(char *cmd)
{
	char	**res;
	int		cnt;

	cnt = cnt_cmd(cmd);
	res = malloc(sizeof(char *) * (cnt + 1));
	if (!res)
		return (0);
	if (!do_split_cmd(res, cmd, cnt))
	{
		free_split(res);
		return (0);
	}
	return (res);
}
