/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_error_deal3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:24:59 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/13 12:40:45 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end_err_memory_lack7(t_philo **philos, t_public *public, int i)
{
	int	a;

	free_public(public);
	a = 0;
	while (a < i)
	{
		free(philos[a]->private);
		free(philos[a]);
		a++;
	}
	free(philos[i]);
	free(philos);
	return (ERR_MEMORY_LACK);
}

int	end_err(int errno)
{
	print_err(errno);
	return (0);
}
