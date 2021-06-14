/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:18:27 by sangjeon          #+#    #+#             */
/*   Updated: 2021/06/12 17:51:30 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putwchar_fd.h"

static void		putwchar_utf8_4(int wc, int fd)
{
	unsigned char	out;

	out = (wc >> 18) | 0b11110000;
	write(fd, &out, 1);
	out = (wc >> 12 & 0b111111) | 0b10000000;
	write(fd, &out, 1);
	out = (wc >> 6 & 0b111111) | 0b10000000;
	write(fd, &out, 1);
	out = (wc & 0b111111) | 0b10000000;
	write(fd, &out, 1);
}

static void		putwchar_utf8_3(int wc, int fd)
{
	unsigned char	out;

	out = (wc >> 12) | 0b11100000;
	write(fd, &out, 1);
	out = (wc >> 6 & 0b111111) | 0b10000000;
	write(fd, &out, 1);
	out = (wc & 0b111111) | 0b10000000;
	write(fd, &out, 1);
}

static void		putwchar_utf8_2(int wc, int fd)
{
	unsigned char	out;

	out = (wc >> 6) | 0b11000000;
	write(fd, &out, 1);
	out = (wc & 0b111111) | 0b10000000;
	write(fd, &out, 1);
}

static void		putwchar_utf8_1(int wc, int fd)
{
	unsigned char	out;

	out = wc;
	write(fd, &out, 1);
}

void			ft_putwchar_fd(int wc, int fd)
{
	if (wc <= UTF8_1)
		putwchar_utf8_1(wc, fd);
	else if (wc <= UTF8_2)
		putwchar_utf8_2(wc, fd);
	else if (wc <= UTF8_3)
		putwchar_utf8_3(wc, fd);
	else if (wc <= UTF8_4)
		putwchar_utf8_4(wc, fd);
}
