/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:20:08 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/13 09:16:37 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>

# define SUCCEESS 0
# define ERR_OUT_RANGE 1
# define ERR_MEMORY_LACK 2
# define ERR_TIME 3
# define ERR_MUTEX 4

void	print_err(int errorno);

#endif
