/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_perr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:49:12 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:58 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_perr.h"

char	*custom_strerror(int num)
{
	if (num == EUNEXPECTED)
		return ("syntax error unexpected char");
	if (num == EUNCLOSED)
		return ("syntax error unclosed quotes");
	return ("unknown error");
}

void	put_custom_errmsg(void)
{
	ft_putstr_fd(custom_strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	errno = 0;
}

void	put_std_errmsg(void)
{
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	errno = 0;
}

void	put_errmsg(void)
{
	if (errno != 0)
		put_custom_errmsg();
	if (errno != 0)
		put_std_errmsg();
}
