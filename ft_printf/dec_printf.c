/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:12:06 by sangjeon          #+#    #+#             */
/*   Updated: 2021/07/14 11:28:55 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_decprintf(double dec, int *size, t_conf *p_conf)
{
	t_dtob	dtob;

	dtob.val = dec;
	printf("do_decprintf -- %f\n", dtob.val);
}
