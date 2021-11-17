/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 08:38:49 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/17 09:20:15 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include "error.h"

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIED 5

# define END 0
# define RUNNING 1

# define IDX_PHILO_NMB 1
# define IDX_DIE_T 2
# define IDX_EAT_T 3
# define IDX_SLEEP_T 4
# define IDX_EAT_NMB 5

# define DEFAULT_EAT_CNT -2

typedef struct s_private
{
	char			state;
	int				id;
	int				eat_cnt;
	long long		eat_t;
	long long		change_t;
}	t_private;

typedef struct s_public
{
	int				*end_sig;
	int				philo_nmb;
	int				die_term;
	int				eat_term;
	int				sleep_term;
	int				eat_cnt;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*mutex_g;
	long long		start_t;
}	t_public;

typedef struct s_philo
{
	t_private	*private;
	t_public	*public;
	pthread_t	philo_tid;
}	t_philo;

void		print_change_state(t_philo *philo);
int			end_err(int errno);
int			end_err_out_range(t_public *public);
int			end_err_memory_lack1(t_public *public);
int			end_err_memory_lack2(t_public *public);
int			end_err_memory_lack3(t_public *public);
int			end_err_memory_lack4(t_public *public, int i);
int			end_err_memory_lack5(t_public *public);
int			end_err_memory_lack6(t_philo **philos, t_public *public, int i);
int			end_err_memory_lack7(t_philo **philos, t_public *public, int i);
int			end_err_time(t_public *public);
int			end_err_mutex(t_public *public);
int			end_err_mutex2(t_public *public, int i);
int			init(int argc, char **argv, t_philo ***philos_ptr, \
t_public **public_ptr);
int			init_public(int argc, char **argv, t_public *public);
int			init_public_mutex(t_public *public);
int			simple_atoi(const char *str);
void		free_public(t_public *public);
void		*philo_routine(void *arg);
void		philo_usleep(t_philo *philo, int term);
long long	get_curtime(void);
void		monitoring(t_philo **philos, t_public *public);

#endif
