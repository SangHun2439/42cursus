/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:47:02 by jeson             #+#    #+#             */
/*   Updated: 2022/01/21 11:30:37 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export_err(char *str)
{
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd("\': not a valid identifier", STDERR_FILENO);
	return (1);
}

int	is_valid_str(char *str)
{
	int	i;
	int	len_to_equ;
	int	flg_valid_str;

	flg_valid_str = 0;
	len_to_equ = length_to_equ(str);
	if (ft_isdigit(str[0]))
		return (0);
	i = 0;
	while (i < len_to_equ)
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			flg_valid_str = 1;
		else
		{
			flg_valid_str = 0;
			break ;
		}
		i++;
	}
	if (flg_valid_str == 1)
		return (1);
	return (0);
}

int	is_valid_form_export(char *str, int	*cnt)
{
	int	i;
	int	idx;

	i = -1;
	*cnt = 0;
	while (str[++i])
	{
		if (str[i] == '=')
		{
			*cnt = 1;
			idx = i;
		}
	}
	if (idx != 0)
		return (1);
	return (0);
}

void	export_env(char *argv, int *cnt)
{
	t_list	*env_list;
	t_env	*env;
	char	*envp;

	envp = ft_strndup(argv, length_to_equ(argv));
	if (!envp)
		init_err();
	env = malloc(sizeof(t_env));
	if (!env)
		init_err();
	env->key = envp;
	env->val = cut_val(argv);
	if (*cnt > 0)
		env->flag = 0;
	else
		env->flag = 1;
	env_list = ft_lstnew(env);
	if (!env_list)
		init_err();
	ft_lstadd_back(&g_vars.env_list, env_list);
}

int	ft_export(t_cmd *cmd)
{
	int	i;
	int	res;
	int	flg_form;
	int	cnt;

	i = 0;
	flg_form = 0;
	if (!cmd->argv[1])
		return (export_no_parm());
	while (cmd->argv[++i])
	{
		if (!is_valid_str(cmd->argv[i]))
			return (ft_export_err(cmd->argv[i]));
		flg_form = is_valid_form_export(cmd->argv[i], &cnt);
		if (flg_form == 1)
		{
			res = is_key(cmd->argv[i]);
			if (res == 1)
				env_overriding(cmd->argv[i], &cnt);
			else
				export_env(cmd->argv[i], &cnt);
		}
	}
	return (0);
}
