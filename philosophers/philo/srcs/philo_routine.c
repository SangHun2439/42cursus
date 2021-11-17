/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:54:55 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/17 08:43:15 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think_routine(t_philo *philo, int id)
{
	if (id % 2 == 1)
	{
		pthread_mutex_lock(philo->public->forks[id % philo->public->philo_nmb]);
		philo->private->change_t = get_curtime();
		philo->private->state = FORK;
		print_change_state(philo);
		pthread_mutex_lock(philo->public->forks[id - 1]);
		philo->private->change_t = get_curtime();
		print_change_state(philo);
	}
	else
	{
		pthread_mutex_lock(philo->public->forks[id - 1]);
		philo->private->change_t = get_curtime();
		philo->private->state = FORK;
		print_change_state(philo);
		pthread_mutex_lock(philo->public->forks[id % philo->public->philo_nmb]);
		philo->private->change_t = get_curtime();
		print_change_state(philo);
	}
	philo->private->state = EAT;
}

void	eat_routine(t_philo *philo, int id)
{
	philo->private->change_t = get_curtime();
	philo->private->eat_t = get_curtime();
	print_change_state(philo);
	philo_usleep(philo, philo->public->eat_term);
	if (philo->private->eat_cnt != DEFAULT_EAT_CNT)
		philo->private->eat_cnt--;
	pthread_mutex_unlock(philo->public->forks[id % philo->public->philo_nmb]);
	pthread_mutex_unlock(philo->public->forks[id - 1]);
	philo->private->state = SLEEP;
}

void	sleep_routine(t_philo *philo)
{
	philo->private->change_t = get_curtime();
	print_change_state(philo);
	philo_usleep(philo, philo->public->sleep_term);
	philo->private->state = THINK;
	philo->private->change_t = get_curtime();
	print_change_state(philo);
}

void	*philo_routine(void *philo)
{
	while (1)
	{
		if (*(((t_philo *)philo)->public->end_sig) == END)
			return (0);
		if ((((t_philo *)philo)->private->eat_cnt) == 0)
			return (0);
		if (((t_philo *)philo)->private->state == THINK)
			think_routine(philo, ((t_philo *)philo)->private->id);
		else if (((t_philo *)philo)->private->state == EAT)
			eat_routine(philo, ((t_philo *)philo)->private->id);
		else if (((t_philo *)philo)->private->state == SLEEP)
			sleep_routine(philo);
	}
}
