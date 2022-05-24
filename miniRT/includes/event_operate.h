/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_operate.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:40:14 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/24 23:12:52 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_OPERATE_H
# define EVENT_OPERATE_H

# include <stdlib.h>
# include "mlx.h"
# include "minirt_objs.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_RED_BUTTON_PRESS 17

# define KEY_ESC 53

int	key_press(int key_code, t_minirt *rt);
int	red_button_press(t_minirt *rt);

#endif
