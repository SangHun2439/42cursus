/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 07:31:48 by sangjeon          #+#    #+#             */
/*   Updated: 2021/06/12 18:10:17 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strnlen(char const *str, int n)
{
	int		res;

	res = 0;
	while (*str++ && n--)
		res++;
	return (res);
}

void	count_putchar_fd(char c, int fd, int *size)
{
	write(fd, &c, 1);
	*size = *size + 1;
}

char	*ft_strndup(char const *str, size_t len)
{
	char		*res;
	size_t		i;

	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		addr_mov_atoi(const char **s)
{
	int		res;

	res = 0;
	while (ft_isdigit(**s))
	{
		res *= 10;
		res += **s - '0';
		*s = *s + 1;
	}
	return (res);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;

	len = (int)ft_strlen(base);
	if (nbr == -2147483648)
	{
		write(1, &"-", 1);
		ft_putnbr_base((nbr / len) * -1, base);
		ft_putnbr_base((nbr % len) * -1, base);
		return ;
	}
	if (nbr < 0)
	{
		write(1, &"-", 1);
		nbr = -nbr;
	}
	if (nbr < len)
	{
		write(1, base + nbr, 1);
		return ;
	}
	ft_putnbr_base(nbr / len, base);
	ft_putnbr_base(nbr % len, base);
}
