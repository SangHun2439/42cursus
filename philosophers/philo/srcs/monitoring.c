/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:12:49 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/24 08:45:41 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo **philos, t_public *public)
{
	int			i;
	long long	cur_time;

	i = 0;
	while (i < public->philo_nmb)
	{
		cur_time = get_curtime();
		if (cur_time - philos[i]->private->eat_t > philos[i]->public->die_term)
		{
			philos[i]->private->state = DIED;
			philos[i]->private->change_t = cur_time;
			print_change_state(philos[i]);
			*(public->end_sig) = END;
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_all_eat(t_philo **philos, t_public *public)
{
	int	i;

	i = 0;
	while (i < public->philo_nmb)
	{
		if (philos[i]->private->eat_cnt != 0)
			return (0);
		i++;
	}
	*(public->end_sig) = END;
	return (1);
}

void	monitoring(t_philo **philos, t_public *public)
{
	while (1)
	{
		if (is_dead(philos, public) || is_all_eat(philos, public) || \
		*(public->end_sig) == END)
			return ;
	}
}
