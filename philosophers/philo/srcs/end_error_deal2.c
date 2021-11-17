/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_error_deal2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 08:54:48 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/13 10:30:04 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end_err_mutex(t_public *public)
{
	free(public->end_sig);
	free(public->forks);
	free(public->mutex_g);
	free(public);
	return (ERR_MUTEX);
}

int	end_err_mutex2(t_public *public, int i)
{
	int	a;

	free(public->end_sig);
	a = 0;
	while (a < i)
	{
		pthread_mutex_destroy(public->forks[a]);
		free(public->forks[a]);
		a++;
	}
	free(public->forks[i]);
	free(public->forks);
	free(public->mutex_g);
	free(public);
	return (ERR_MUTEX);
}

int	end_err_memory_lack4(t_public *public, int i)
{
	int	a;

	free(public->end_sig);
	a = 0;
	while (a < i)
	{
		pthread_mutex_destroy(public->forks[a]);
		free(public->forks[a]);
		a++;
	}
	free(public->forks);
	free(public->mutex_g);
	free(public);
	return (ERR_MEMORY_LACK);
}

int	end_err_memory_lack5(t_public *public)
{
	free_public(public);
	return (ERR_MEMORY_LACK);
}

int	end_err_memory_lack6(t_philo **philos, t_public *public, int i)
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
	free(philos);
	return (ERR_MEMORY_LACK);
}
