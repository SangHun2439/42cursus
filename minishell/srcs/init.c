/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:11:45 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/23 22:05:01 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	envp_to_list(char **envp)
{
	int		len;
	t_env	*env;
	t_list	*env_list;

	while (*envp)
	{
		env = malloc(sizeof(t_env));
		if (!env)
			init_err();
		len = length_to_equ(*envp);
		env->key = ft_strndup(*envp, len);
		env->val = ft_strdup(*envp + len + 1);
		if (!env->key || !env->val)
			init_err();
		env->flag = 0;
		env_list = ft_lstnew(env);
		if (!env_list)
			init_err();
		ft_lstadd_back(&g_vars.env_list, env_list);
		envp++;
	}
}

int	init(char **argv, t_list **cmd_list_ptr, char **envp)
{
	(void)argv;
	ft_lstclear(&g_vars.env_list, del_env_one);
	envp_to_list(envp);
	*cmd_list_ptr = 0;
	g_vars.last_status = 0;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	return (0);
}
