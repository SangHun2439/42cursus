/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:59:57 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:58 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_list		*cmd_list;
	int			parse_status;

	if (argc != 1)
		return (0);
	init(argv, &cmd_list, envp);
	while (1)
	{
		line = rl_gets();
		parse_status = parse_cmd(&cmd_list, line);
		if (parse_status != EMPTYLINE)
			g_vars.last_status = parse_status;
		if (parse_status == 0)
			g_vars.last_status = exec_cmd(cmd_list);
		ft_lstclear(&cmd_list, del_cmd);
	}
}
