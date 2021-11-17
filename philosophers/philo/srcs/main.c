/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:03:50 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/17 09:21:38 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		**philos;
	t_public	*public;
	int			err;
	int			i;

	if (argc != 5 && argc != 6)
		return (0);
	err = init(argc, argv, &philos, &public);
	if (err)
		return (end_err(err));
	i = 0;
	while (i < public->philo_nmb)
	{
		if (pthread_create(&(philos[i]->philo_tid), 0, philo_routine, \
		philos[i]) || pthread_detach(philos[i]->philo_tid))
			return (0);
		i++;
	}
	monitoring(philos, public);
	return (0);
}
