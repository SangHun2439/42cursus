/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:02:43 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:35 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	list_clear(t_list **cmd_line_list_ptr, t_list **redi_list_ptr)
{
	ft_lstclear(cmd_line_list_ptr, free);
	ft_lstclear(redi_list_ptr, del_redi_one);
	return (0);
}

int	is_quote(char c)
{
	if (c == '"')
		return (BIG_QUOTE);
	if (c == '\'')
		return (SMALL_QUOTE);
	return (0);
}

int	write_str(char **res, char c, int clear_flag)
{
	static char	buf[PARSE_CMD_BUF_SIZE + 1];
	static int	idx;
	char		*tmp;

	if (clear_flag)
	{
		idx = 0;
		ft_bzero(buf, PARSE_CMD_BUF_SIZE + 1);
		return (0);
	}
	buf[idx++] = c;
	if (c == 0 || idx == PARSE_CMD_BUF_SIZE)
	{
		tmp = *res;
		buf[idx] = 0;
		*res = ft_strjoin(*res, buf);
		idx = 0;
		ft_bzero(buf, PARSE_CMD_BUF_SIZE + 1);
		if (tmp != 0)
			free(tmp);
		if (!*res)
			return (1);
	}
	return (0);
}
