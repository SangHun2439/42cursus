/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:18:44 by sangjeon          #+#    #+#             */
/*   Updated: 2021/10/06 16:46:04 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	s_handler(int signo, siginfo_t *info, void *context)
{
	static char		c;
	static int		bit_cnt;
	unsigned char	bit;

	context = 0;
	bit = 0b10000000;
	if (signo == SIGUSR1)
		bit_cnt++;
	else if (signo == SIGUSR2)
	{
		c |= bit >> bit_cnt;
		bit_cnt++;
	}
	if (bit_cnt == 8)
	{
		ft_putchar_fd(c, 1);
		bit_cnt = 0;
		c = 0;
	}
	if (signo == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signo == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = s_handler;
	act.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	pid = getpid();
	ft_printf("server pid : %d\n", pid);
	while (1)
		;
}
