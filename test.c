/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:48:12 by sangjeon          #+#    #+#             */
/*   Updated: 2021/06/12 19:06:40 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <wchar.h>
#include <unistd.h>
#include <locale.h>

void	input(char **p_str)
{
	*p_str = "hello";
	*p_str = *p_str + 1;
}

int		main(void)
{
	char	*str;
	unsigned char	test2;
	wchar_t test;
	wint_t	test_i;

	setlocale(LC_ALL, "");
	test = L'가';
	test_i = 123;
	input(&str);
	test2 = 234;
	write(1, &test2, 1);
	test2 = 176;
	write(1, &test2, 1);
	test2 = 128;
	write(1, &test2, 1);
	write(1, "\n", 1);
	write(1, &test2, 1);
//	printf("%lc", test);
	printf("\n%d\n", test);
	printf("%d", printf("%-2lc", L'한'));
	return (0);
}
