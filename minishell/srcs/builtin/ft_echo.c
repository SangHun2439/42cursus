/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:16:56 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:13 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isecho_nopt(char *echoopt)
{
	int	i;

	if (ft_strlen(echoopt) < 2)
		return (0);
	if (ft_strncmp(echoopt, "-n", 2) != 0)
		return (0);
	i = 2;
	while (echoopt[i])
	{
		if (echoopt[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(t_cmd *cmd)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (cmd->argv[i] && isecho_nopt(cmd->argv[i]))
	{
		res = -1;
		i++;
	}
	while (cmd->argv[i])
	{
		ft_putstr_fd(cmd->argv[i], 1);
		if (cmd->argv[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		++i;
	}
	if (res != -1)
		ft_putstr_fd("\n", 1);
	return (0);
}
