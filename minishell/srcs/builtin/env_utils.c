/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:09:39 by jeson             #+#    #+#             */
/*   Updated: 2022/01/21 11:56:09 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_overriding(char *str, int *cnt)
{
	t_list	*env_list;
	t_env	*env;
	char	*str_key;

	if (*cnt == 0)
		return ;
	env_list = g_vars.env_list;
	str_key = ft_strndup(str, length_to_equ(str));
	if (!str_key)
		init_err();
	while (env_list)
	{
		env = env_list->content;
		if (!ft_strcmp(env->key, str_key))
		{
			free(env->val);
			env->val = cut_val(str);
		}
		env->flag = 0;
		env_list = env_list->next;
	}
	free(str_key);
}

int	export_no_parm(void)
{
	t_list	*env_list;
	t_env	*env;

	env_list = g_vars.env_list;
	while (env_list)
	{
		env = env_list->content;
		if (env->flag == 0)
			printf("declare -x %s=\"%s\"\n", env->key, env->val);
		else if (env->flag == 1)
			printf("declare -x %s\n", env->key);
		env_list = env_list->next;
	}
	return (0);
}
