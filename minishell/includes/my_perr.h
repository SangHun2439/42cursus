/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_perr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:45:25 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:07:07 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PERR_H
# define MY_PERR_H

# include <errno.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

# define EUNEXPECTED 256
# define EUNCLOSED 257

void	put_errmsg(void);

#endif
