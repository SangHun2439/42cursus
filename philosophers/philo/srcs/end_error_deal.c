/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_error_deal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:29:15 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/17 09:22:13 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end_err_out_range(t_public *public)
{
	free(public);
	return (ERR_OUT_RANGE);
}

int	end_err_memory_lack1(t_public *public)
{
	free(public);
	return (ERR_MEMORY_LACK);
}

int	end_err_memory_lack2(t_public *public)
{
	free(public->end_sig);
	free(public);
	return (ERR_MEMORY_LACK);
}

int	end_err_memory_lack3(t_public *public)
{
	free(public->end_sig);
	free(public->forks);
	free(public);
	return (ERR_MEMORY_LACK);
}

int	end_err_time(t_public *public)
{
	free(public->end_sig);
	free(public);
	return (ERR_TIME);
}
