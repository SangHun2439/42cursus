/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:01:43 by jeson             #+#    #+#             */
/*   Updated: 2022/01/20 23:08:01 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_cmd *cmd)
{
	t_list	*env_list;
	t_env	*env;

	env_list = g_vars.env_list;
	if (cmd->argv[1])
	{
		ft_putendl_fd("env with no options or arguments", STDERR_FILENO);
		return (1);
	}
	while (env_list)
	{
		env = env_list->content;
		if (!env->flag)
			printf("%s=%s\n", env->key, env->val);
		env_list = env_list->next;
	}
	return (0);
}
