/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:41:14 by jeson             #+#    #+#             */
/*   Updated: 2022/01/21 11:57:47 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_form_unset(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (!is_valid_str(str) || ft_strchr(str, '='))
	{
		ft_putstr_fd("unset: `", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putendl_fd("\': not a valid identifier", STDERR_FILENO);
		return (0);
	}
	return (1);
}

t_list	*prev_node(char *str)
{
	t_list	*node_return;
	t_env	*env;
	t_list	*tmp;

	node_return = g_vars.env_list;
	while (node_return)
	{
		if (!node_return->next)
			break ;
		tmp = node_return->next;
		env = tmp->content;
		if (!ft_strcmp(env->key, str))
			return (node_return);
		node_return = node_return->next;
	}
	return (NULL);
}

void	unset_env(char *key)
{
	t_list	*env_list;
	t_env	*env;
	t_list	*prev;

	env_list = g_vars.env_list;
	while (env_list)
	{
		env = env_list->content;
		if (!ft_strcmp(env->key, key))
		{
			prev = prev_node(key);
			if (!prev)
				g_vars.env_list = env_list->next;
			else
				prev->next = env_list->next;
			ft_lstdelone(env_list, del_env_one);
			break ;
		}
		env_list = env_list->next;
	}
}

int	ft_unset(t_cmd *cmd)
{
	int	i;
	int	res;
	int	flg_form;

	i = 0;
	flg_form = 0;
	while (cmd->argv[++i])
	{
		flg_form = is_valid_form_unset(cmd->argv[i]);
		if (!flg_form)
			return (1);
		if (flg_form == 1)
		{
			res = is_key(cmd->argv[i]);
			if (res == 1)
				unset_env(cmd->argv[i]);
			else
				continue ;
		}
	}
	return (0);
}
