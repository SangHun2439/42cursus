/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:44:14 by sangjeon          #+#    #+#             */
/*   Updated: 2021/10/06 16:47:33 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_check;

void	c_handler(int signo)
{
	if (signo == SIGUSR1 || signo == SIGUSR2)
		g_check = 1;
}

void	send_server(int server_pid, char a)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (a & bit)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		bit = bit >> 1;
		while (!g_check)
			;
		g_check = 0;
	}
}

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*msg;
	struct sigaction	act;

	if (argc != 3)
		return (0);
	g_check = 0;
	server_pid = ft_atoi(argv[1]);
	msg = argv[2];
	sigemptyset(&act.sa_mask);
	act.sa_handler = c_handler;
	act.sa_flags = SA_NODEFER;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (*msg)
		send_server(server_pid, *msg++);
	return (0);
}
