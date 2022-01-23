/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:20:57 by jeson             #+#    #+#             */
/*   Updated: 2022/01/21 11:55:51 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd_err(int error, char *dir)
{
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd(dir, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(error), STDERR_FILENO);
	return (1);
}

int	ft_home_not_set(void)
{
	ft_putendl_fd("cd: HOME not set", STDERR_FILENO);
	return (1);
}

int	length_to_equ(const char *str)
{
	size_t	i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

char	*cut_val(char *str)
{
	char	*env_val;
	int		len_equ;
	int		len;

	len = ft_strlen(str);
	len_equ = length_to_equ(str);
	if (len - len_equ == 1)
		env_val = ft_strdup("");
	else
		env_val = ft_strndup(&str[len_equ + 1], (len - len_equ - 1));
	if (!env_val)
		init_err();
	return (env_val);
}
