/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 02:11:36 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/21 11:47:45 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
		free(str_arr[i++]);
	free(str_arr);
}

char	*ft_strndup(const char *s1, size_t max)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (max + 1));
	if (!res)
		return (0);
	i = 0;
	while (s1[i] && i < max)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*find_val(char *str)
{
	t_list	*env_list;
	t_env	*env;

	env_list = g_vars.env_list;
	while (env_list)
	{
		env = env_list->content;
		if (!ft_strcmp(env->key, str))
			return (env->val);
		env_list = env_list->next;
	}
	return (0);
}

int	is_key(char *str)
{
	t_list	*env_list;
	t_env	*env;
	char	*str_key;

	env_list = g_vars.env_list;
	str_key = ft_strndup(str, length_to_equ(str));
	if (!str_key)
		init_err();
	while (env_list)
	{
		env = env_list->content;
		if (!ft_strcmp(env->key, str_key))
		{
			free(str_key);
			return (1);
		}
		env_list = env_list->next;
	}
	free(str_key);
	return (0);
}

void	del_env_one(void *content)
{
	t_env	*env;

	env = content;
	if (!env)
		return ;
	if (env->key)
		free(env->key);
	if (env->val)
		free(env->val);
	free(env);
}
