/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:49:39 by jeson             #+#    #+#             */
/*   Updated: 2022/01/20 18:26:04 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*format_one(t_env *env)
{
	char	*res;
	char	*tmp;
	int		i;

	res = malloc(sizeof(char) * \
	(ft_strlen(env->key) + ft_strlen(env->val) + 2));
	if (!res)
		return (0);
	tmp = env->key;
	i = 0;
	while (*tmp)
		res[i++] = *tmp++;
	res[i++] = '=';
	tmp = env->val;
	while (*tmp)
		res[i++] = *tmp++;
	res[i] = 0;
	return (res);
}

int	envp_len(void)
{
	t_list	*env_list;
	t_env	*env;
	int		len;

	env_list = g_vars.env_list;
	len = 0;
	while (env_list)
	{
		env = env_list->content;
		if (!env->flag)
			len++;
		env_list = env_list->next;
	}
	return (len);
}

void	format_envp_init(char ***arr_ptr)
{
	if (*arr_ptr)
	{
		free_split(*arr_ptr);
		*arr_ptr = 0;
	}
}

char	**format_envp_err(char ***arr_ptr)
{
	free_split(*arr_ptr);
	*arr_ptr = 0;
	return (0);
}

char	**format_envp(void)
{
	static char	**arr;
	int			i;
	t_list		*env_list;
	t_env		*env;

	format_envp_init(&arr);
	env_list = g_vars.env_list;
	i = 0;
	arr = malloc(sizeof(char *) * (envp_len() + 1));
	if (!arr)
		return (0);
	i = 0;
	while (env_list)
	{
		env = env_list->content;
		env_list = env_list->next;
		if (env->flag)
			continue ;
		arr[i] = format_one(env);
		if (!arr[i])
			return (format_envp_err(&arr));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
