/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:35:16 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/17 09:25:22 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_public_mutex(t_public *public)
{
	int	i;

	public->forks = malloc(sizeof(pthread_mutex_t) * public->philo_nmb);
	if (!public->forks)
		return (end_err_memory_lack2(public));
	public->mutex_g = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!public->mutex_g)
		return (end_err_memory_lack3(public));
	if (pthread_mutex_init(public->mutex_g, 0) != 0)
		return (end_err_mutex(public));
	i = 0;
	while (i < public->philo_nmb)
	{
		public->forks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!public->forks[i])
			return (end_err_memory_lack4(public, i));
		if (pthread_mutex_init(public->forks[i], 0) != 0)
			return (end_err_mutex2(public, i));
		i++;
	}
	return (SUCCEESS);
}

int	init_public(int argc, char **argv, t_public *public)
{
	public->philo_nmb = simple_atoi(argv[IDX_PHILO_NMB]);
	public->die_term = simple_atoi(argv[IDX_DIE_T]);
	public->eat_term = simple_atoi(argv[IDX_EAT_T]);
	public->sleep_term = simple_atoi(argv[IDX_SLEEP_T]);
	public->eat_cnt = DEFAULT_EAT_CNT;
	if (argc == 6)
		public->eat_cnt = simple_atoi(argv[IDX_EAT_NMB]);
	if (public->philo_nmb == -1 || public->die_term == -1 || public->\
	eat_term == -1 || public->sleep_term == -1 || public->eat_cnt == -1)
		return (end_err_out_range(public));
	public->end_sig = (int *)malloc(sizeof(int));
	if (!public->end_sig)
		return (end_err_memory_lack1(public));
	*(public->end_sig) = RUNNING;
	public->start_t = get_curtime();
	return (init_public_mutex(public));
}

int	init_private(t_philo **philos, t_public *public)
{
	int	i;

	i = 0;
	while (i < public->philo_nmb)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philos[i])
			return (end_err_memory_lack6(philos, public, i));
		philos[i]->public = public;
		philos[i]->private = (t_private *)malloc(sizeof(t_private));
		if (!philos[i]->private)
			return (end_err_memory_lack7(philos, public, i));
		philos[i]->private->id = i + 1;
		philos[i]->private->eat_cnt = public->eat_cnt;
		philos[i]->private->state = THINK;
		philos[i]->private->eat_t = public->start_t;
		i++;
	}
	return (SUCCEESS);
}

int	init(int argc, char **argv, t_philo ***philos_ptr, t_public **public_ptr)
{
	t_public	*public;
	t_philo		**philos;
	int			err;

	err = 0;
	public = (t_public *)malloc(sizeof(t_public));
	if (!public)
		return (ERR_MEMORY_LACK);
	memset(public, 0, sizeof(t_public));
	err = init_public(argc, argv, public);
	if (err)
		return (err);
	*public_ptr = public;
	philos = (t_philo **)malloc(sizeof(t_philo *) * public->philo_nmb);
	if (!philos)
		return (end_err_memory_lack5(public));
	err = init_private(philos, public);
	if (err)
		return (err);
	*philos_ptr = philos;
	return (SUCCEESS);
}
