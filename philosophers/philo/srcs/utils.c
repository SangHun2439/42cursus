/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:38:52 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/16 22:46:57 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_change_state(t_philo *philo)
{
	char		*state;

	if (philo->private->state == FORK)
		state = "take fork";
	else if (philo->private->state == EAT)
		state = "start eat";
	else if (philo->private->state == SLEEP)
		state = "start sleep";
	else if (philo->private->state == THINK)
		state = "start think";
	else
		state = "died";
	pthread_mutex_lock(philo->public->mutex_g);
	printf("ID : %d philosopher %s --- %lld ms\n", philo->private->id, \
	state, philo->private->change_t - philo->public->start_t);
	pthread_mutex_unlock(philo->public->mutex_g);
}

int	simple_atoi(const char *str)
{
	long long	res;

	res = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (res > 2147483647)
			return (-1);
		res *= 10;
		res += *str - '0';
		str++;
	}
	if (*str)
		return (-1);
	return (res);
}

long long	get_curtime(void)
{
	struct timeval	time;

	gettimeofday(&(time), 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	philo_usleep(t_philo *philo, int term)
{
	while (get_curtime() - philo->private->change_t < term)
		usleep(50);
}
