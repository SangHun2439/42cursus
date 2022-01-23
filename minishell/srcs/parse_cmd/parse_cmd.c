/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:59:16 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:37 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_cmd(char *cmd)
{
	int	quote_flag;

	quote_flag = 0;
	while (*cmd)
	{
		quote_check(&quote_flag, *cmd);
		if (!quote_flag && *cmd == '(')
			return (0);
		if (!quote_flag && *cmd == ')')
			return (0);
		if (!quote_flag && *cmd == '*')
			return (0);
		if (!quote_flag && *cmd == '&')
			return (0);
		if (!quote_flag && *cmd == '#')
			return (0);
		if (!quote_flag && *cmd == '\\')
			return (0);
		if (!quote_flag && *cmd == ';')
			return (0);
		if (!quote_flag && ft_strncmp(cmd, "||", 2) == 0)
			return (0);
		cmd++;
	}
	return (1);
}

int	parse_init(char **line_ptr, char ***cmd_arr_ptr)
{
	if (!is_valid_cmd(*line_ptr))
		return (parse_unexpected_err());
	while (**line_ptr && _isspace(**line_ptr))
		(*line_ptr)++;
	if (!(**line_ptr))
		return (EMPTYLINE);
	if (**line_ptr == '|')
		return (parse_unexpected_err());
	*cmd_arr_ptr = split_cmd(*line_ptr);
	if (!*cmd_arr_ptr)
		return (parse_err());
	return (0);
}

int	init_cmd(t_list *cmd_line_list, t_list *redi_list, t_cmd **cmd_ptr)
{
	t_list	*lst;

	if (!cmd_line_list && !redi_list)
		return (parse_unexpected_err());
	*cmd_ptr = (t_cmd *)malloc(sizeof(t_cmd));
	if (!*cmd_ptr)
		return (parse_err_mem3(&cmd_line_list, &redi_list));
	(*cmd_ptr)->argv = list_to_arr(cmd_line_list);
	while (cmd_line_list)
	{
		lst = cmd_line_list;
		cmd_line_list = cmd_line_list->next;
		free(lst);
	}
	if (!(*cmd_ptr)->argv)
	{
		free(*cmd_ptr);
		list_clear(&cmd_line_list, &redi_list);
		return (FAIL);
	}
	(*cmd_ptr)->redi_list = redi_list;
	return (SUCCESS);
}

int	parse_one_cmd(char *one_cmd, t_cmd **cmd_ptr)
{
	t_list	*cmd_line_list;
	t_list	*redi_list;
	int		res;

	cmd_line_list = 0;
	redi_list = 0;
	res = 0;
	while (*one_cmd)
	{
		if (!_isspace(*one_cmd))
		{
			res = fill_cmd_redi_list(&one_cmd, &cmd_line_list, &redi_list);
			if (res != 0)
				return (res);
		}
		else
			one_cmd++;
	}
	if (res != 0)
		return (parse_err_mem3(&cmd_line_list, &redi_list));
	return (init_cmd(cmd_line_list, redi_list, cmd_ptr));
}

int	parse_cmd(t_list **cmd_list_ptr, char *line)
{
	char	**cmd_arr;
	int		i;
	t_cmd	*cmd;
	t_list	*new_lst;
	int		res;

	res = parse_init(&line, &cmd_arr);
	if (res != 0)
		return (res);
	i = 0;
	while (cmd_arr[i])
	{
		res = parse_one_cmd(cmd_arr[i], &cmd);
		if (res != 0)
			return (parse_err_cmd(cmd_arr, res));
		new_lst = ft_lstnew(cmd);
		if (!new_lst)
			return (parse_err_mem2(cmd_arr, cmd));
		ft_lstadd_back(cmd_list_ptr, new_lst);
		i++;
	}
	free_split(cmd_arr);
	return (0);
}
