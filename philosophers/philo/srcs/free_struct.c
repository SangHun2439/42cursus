/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 09:24:06 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/13 10:15:58 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_public(t_public *public)
{
	int	i;

	free(public->end_sig);
	pthread_mutex_destroy(public->mutex_g);
	free(public->mutex_g);
	i = 0;
	while (i < public->philo_nmb)
	{
		pthread_mutex_destroy(public->forks[i]);
		free(public->forks[i]);
		i++;
	}
	free(public->forks);
	free(public);
}

void	free_philo(t_philo *philo)
{
	free_public(philo->public);
	free(philo->private);
	free(philo);
}
