/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:22:53 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/12 22:25:36 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	err_out_range(void)
{
	printf("error! please put positive integer\n");
}

void	err_memory_lack(void)
{
	printf("error! memory is not enough\n");
}

void	err_time(void)
{
	printf("error! function gettimeofday error\n");
}

void	err_mutex(void)
{
	printf("error! fail mutex init\n");
}

void	print_err(int errorno)
{
	if (errorno == ERR_OUT_RANGE)
		return (err_out_range());
	if (errorno == ERR_MEMORY_LACK)
		return (err_memory_lack());
	if (errorno == ERR_TIME)
		return (err_time());
	if (errorno == ERR_MUTEX)
		return (err_mutex());
}
