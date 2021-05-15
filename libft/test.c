/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:16:17 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/15 20:02:43 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int		main()
{
	char	arr[] = "hello this is test";
	int		int_arr[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	char	arr2[] = "hello this is test";
	int		int_arr2[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	printf("======memset======\n");
	printf("%s\n", arr);
	ft_memset(arr, 'c', 10);
	printf("%s\n", arr);
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", int_arr[i]);
	}
	printf("\n");
	ft_memset(int_arr, 0, sizeof(int_arr));
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", int_arr[i]);
	}

	printf("\n!!!!!!answer!!!!!!!\n");
	printf("%s\n", arr2);
	memset(arr2, 'c', 10);
	printf("%s\n", arr2);
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", int_arr2[i]);
	}
	printf("\n");
	memset(int_arr2, 0, sizeof(int_arr2));
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", int_arr2[i]);
	}

	printf("\n======strrchr======\n");
	char	*str = "b2 b2 f1 f2 f3 f4 f5";
	printf("%s\n", ft_strrchr(str, 'f'));
	printf("%s\n", ft_strrchr(str, '\0'));
	printf("%s\n", ft_strrchr(str, 'a'));

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%s\n", strrchr(str, 'f'));
	printf("%s\n", strrchr(str, '\0'));
	printf("%s\n", strrchr(str, 'a'));

	printf("\n======bzero======\n");
	char	arr3[] = "hello this is test";
	int		int_arr3[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	char	arr4[] = "hello this is test";
	int		int_arr4[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	printf("%s\n", arr3);
	ft_bzero(arr3, 10);
	printf("%s\n", arr3);
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", int_arr3[i]);
	}
	printf("\n");
	ft_bzero(int_arr3, sizeof(int_arr3));
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", int_arr3[i]);
	}

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%s\n", arr4);
	bzero(arr4, 10);
	printf("%s\n", arr4);
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", int_arr4[i]);
	}
	printf("\n");
	bzero(int_arr4, sizeof(int_arr4));
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", int_arr4[i]);
	}

	printf("\n======strnstr======\n");
	char big[] = "go go yogurt";
	char little[] = "gu";
	printf("%s\n", ft_strnstr(big, "", 9));
	printf("%s\n", ft_strnstr(big,little,14));
	printf("%s\n", ft_strnstr(big,little,9));
	printf("\n!!!!!!answer!!!!!!\n");
	printf("%s\n", strnstr(big, "", 9));
	printf("%s\n", strnstr(big,little,14));
	printf("%s\n", strnstr(big,little,9));

	printf("\n======memcpy======\n");
	char *srcs = "HelloWorld";
	char *nul_srcs = 0;
	char *nul_dst = 0;
	char *nul_dst2 = 0;
	char dst[20] = {'f', 'a'};
	char dst2[20] = {'f', 'a'};
	printf("%s\n", dst);
	ft_memcpy(dst, srcs, 11);
	printf("%s\n", dst);

//	printf("%s\n", nul_dst);
//	ft_memcpy(nul_dst, srcs, 11);
//	printf("%s\n", nul_dst);
//	nul_dst = 0;

//	printf("%s\n", dst);
//	ft_memcpy(dst, nul_srcs, 11);
//	printf("%s\n", dst);

	printf("%s\n", nul_dst);
	ft_memcpy(nul_dst, nul_srcs, 11);
	printf("%s\n", nul_dst);

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%s\n", dst2);
	memcpy(dst2, srcs, 11);
	printf("%s\n", dst2);

//	printf("%s\n", nul_dst2);
//	memcpy(nul_dst2, srcs, 11);
//	printf("%s\n", nul_dst2);
//	nul_dst2 = 0;

//	printf("%s\n", dst2);
//	memcpy(dst2, nul_srcs, 11);
//	printf("%s\n", dst2);

	printf("%s\n", nul_dst2);
	memcpy(nul_dst2, nul_srcs, 11);
	printf("%s\n", nul_dst2);

	printf("\n======strncmp======\n");
	char str1[] = "BlockDMask";
    char str2[] = "Block";
    char str3[] = "abcdefghi";
    printf("%d\n", ft_strncmp(str1, str2, -1));
    printf("%d\n", ft_strncmp(str1, str2, 0));
    printf("%d\n", ft_strncmp(str1, str2, 5));
    printf("%d\n", ft_strncmp(str1, str2, 6));
    printf("%d\n", ft_strncmp(str1, str2, 1000));
    printf("%d\n", ft_strncmp(str1, str3, 5));
    printf("%d\n", ft_strncmp(str1, str3, 555));

	printf("\n!!!!!!answer!!!!!!\n");
    printf("%d\n", strncmp(str1, str2, -1));
    printf("%d\n", strncmp(str1, str2, 0));
    printf("%d\n", strncmp(str1, str2, 5));
    printf("%d\n", strncmp(str1, str2, 6));
    printf("%d\n", strncmp(str1, str2, 1000));
    printf("%d\n", strncmp(str1, str3, 5));
    printf("%d\n", strncmp(str1, str3, 555));

	printf("\n======memccpy======\n");
	char buffer[61];
	char *pdest;
	char buffer2[61];
	char *pdest2;
	char string1[60] = "The quick brown dog jumps over the lazy fo";

	pdest2 = ft_memccpy(buffer2, string1, 's', 60);
	*pdest2 = '\0';
	printf("%s\n", buffer2);

	pdest2 = ft_memccpy(buffer2, string1, 'x', 60);
	printf("%s, %s\n", pdest2, buffer2);

	printf("\n!!!!!!!answer!!!!!!\n");
	pdest = memccpy( buffer, string1, 's', 60 );
	*pdest = '\0';
	printf( "%s\n", buffer );

	pdest = memccpy(buffer, string1, 'x', 60);
	printf("%s, %s\n", pdest, buffer);

//	memccpy(nul_dst, nul_srcs, 's', 60);

	printf("\n======memmove======\n");
	char *mo_srcs = "HelloWorld";
	char *mo_nul_srcs = 0;
	char *mo_nul_dst = 0;
	char *mo_nul_dst2 = 0;
	char mo_dst[20] = {'f', 'a'};
	char mo_dst2[20] = {'f', 'a'};
	printf("%s\n", mo_dst);
	ft_memcpy(mo_dst, mo_srcs, 11);
	printf("%s\n", mo_dst);

//	printf("%s\n", mo_nul_dst);
//	ft_memmove(mo_nul_dst, mo_srcs, 11);
//	printf("%s\n", mo_nul_dst);
//	mo_nul_dst = 0;

//	printf("%s\n", mo_dst);
//	ft_memmove(mo_dst, mo_nul_srcs, 11);
//	printf("%s\n", mo_dst);

	printf("%s\n", mo_nul_dst);
	ft_memcpy(mo_nul_dst, mo_nul_srcs, 11);
	printf("%s\n", mo_nul_dst);

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%s\n", mo_dst2);
	memmove(mo_dst2, mo_srcs, 11);
	printf("%s\n", mo_dst2);

//	printf("%s\n", mo_nul_dst2);
//	memmove(mo_nul_dst2, mo_srcs, 11);
//	printf("%s\n", mo_nul_dst2);
//	mo_nul_dst2 = 0;

//	printf("%s\n", mo_dst2);
//	memmove(mo_dst2, mo_nul_srcs, 11);
//	printf("%s\n", mo_dst2);

	printf("%s\n", mo_nul_dst2);
	memmove(mo_nul_dst2, mo_nul_srcs, 11);
	printf("%s\n", mo_nul_dst2);

	printf("\n======isalpha======\n");
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha('l'));
	printf("%d\n", ft_isalpha('B'));
	printf("%d\n", ft_isalpha(999));
	printf("%d\n", ft_isalpha(97));
	printf("%d\n", ft_isalpha(-123));

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%d\n", isalpha('a'));
	printf("%d\n", isalpha('l'));
	printf("%d\n", isalpha('B'));
	printf("%d\n", isalpha(999));
	printf("%d\n", isalpha(97));
	printf("%d\n", isalpha(-123));

	printf("\n======memchr======\n");
	char  *ptr = "falinux.forum.com";
	printf( "%s\n",(char *)ft_memchr( ptr, 'o',  7));
	printf( "%s\n", (char *)ft_memchr( ptr, 'o', 10));

	printf("\n!!!!!!answer!!!!!!\n");
	printf( "%s\n", (char *)memchr( ptr, 'o',  7));
	printf( "%s\n", (char *)memchr( ptr, 'o', 10));

	printf("\n======isdigit======\n");
	printf("%d\n", ft_isdigit(1));
	printf("%d\n", ft_isdigit('1'));
	printf("%d\n", ft_isdigit(58));
	printf("%d\n", ft_isdigit(0));
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", ft_isdigit(48));

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%d\n", isdigit(1));
	printf("%d\n", isdigit('1'));
	printf("%d\n", isdigit(58));
	printf("%d\n", isdigit(0));
	printf("%d\n", isdigit('0'));
	printf("%d\n", isdigit(48));

	printf("\n======memcmp======\n");
	char astr1[] = "BlockDMask";
    char astr2[] = "Block";
    char astr3[] = "abcdefghi";
    printf("%d\n", ft_memcmp(astr1, astr2, 0));
    printf("%d\n", ft_memcmp(astr1, astr2, 5));
    printf("%d\n", ft_memcmp(astr1, astr2, 6));
    printf("%d\n", ft_memcmp(astr1, astr2, 1000));
    printf("%d\n", ft_memcmp(astr1, astr3, 5));
    printf("%d\n", ft_memcmp(astr1, astr3, 555));

	printf("\n!!!!!!answer!!!!!!\n");
    printf("%d\n", memcmp(astr1, astr2, 0));
    printf("%d\n", memcmp(astr1, astr2, 5));
    printf("%d\n", memcmp(astr1, astr2, 6));
    printf("%d\n", memcmp(astr1, astr2, 1000));
    printf("%d\n", memcmp(astr1, astr3, 5));
    printf("%d\n", memcmp(astr1, astr3, 555));

	printf("\n======isalnum======\n");
	printf("%d\n", ft_isalnum(1));
	printf("%d\n", ft_isalnum('1'));
	printf("%d\n", ft_isalnum(58));
	printf("%d\n", ft_isalnum(0));
	printf("%d\n", ft_isalnum('0'));
	printf("%d\n", ft_isalnum(-123));
	printf("%d\n", ft_isalnum('j'));
	printf("%d\n", ft_isalnum('Y'));
	printf("%d\n", ft_isalnum(812));
	printf("%d\n", ft_isalnum('\0'));

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%d\n", isalnum(1));
	printf("%d\n", isalnum('1'));
	printf("%d\n", isalnum(58));
	printf("%d\n", isalnum(0));
	printf("%d\n", isalnum('0'));
	printf("%d\n", isalnum(-123));
	printf("%d\n", isalnum('j'));
	printf("%d\n", isalnum('Y'));
	printf("%d\n", isalnum(812));
	printf("%d\n", isalnum('\0'));

	printf("\n======isascii======\n");
	printf("%d\n", ft_isascii(1));
	printf("%d\n", ft_isascii('1'));
	printf("%d\n", ft_isascii(58));
	printf("%d\n", ft_isascii(0));
	printf("%d\n", ft_isascii('0'));
	printf("%d\n", ft_isascii(-123));
	printf("%d\n", ft_isascii('j'));
	printf("%d\n", ft_isascii('Y'));
	printf("%d\n", ft_isascii(812));
	printf("%d\n", ft_isascii('\0'));
	printf("%d\n", ft_isascii(127));
	printf("%d\n", ft_isascii(128));

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%d\n", isascii(1));
	printf("%d\n", isascii('1'));
	printf("%d\n", isascii(58));
	printf("%d\n", isascii(0));
	printf("%d\n", isascii('0'));
	printf("%d\n", isascii(-123));
	printf("%d\n", isascii('j'));
	printf("%d\n", isascii('Y'));
	printf("%d\n", isascii(812));
	printf("%d\n", isascii('\0'));
	printf("%d\n", isascii(127));
	printf("%d\n", isascii(128));

	printf("\n======isprint======\n");
	printf("%d\n", ft_isprint(1));
	printf("%d\n", ft_isprint('1'));
	printf("%d\n", ft_isprint(58));
	printf("%d\n", ft_isprint(0));
	printf("%d\n", ft_isprint('0'));
	printf("%d\n", ft_isprint(-123));
	printf("%d\n", ft_isprint('j'));
	printf("%d\n", ft_isprint('Y'));
	printf("%d\n", ft_isprint(812));
	printf("%d\n", ft_isprint('\0'));
	printf("%d\n", ft_isprint(127));
	printf("%d\n", ft_isprint(126));

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%d\n", isprint(1));
	printf("%d\n", isprint('1'));
	printf("%d\n", isprint(58));
	printf("%d\n", isprint(0));
	printf("%d\n", isprint('0'));
	printf("%d\n", isprint(-123));
	printf("%d\n", isprint('j'));
	printf("%d\n", isprint('Y'));
	printf("%d\n", isprint(812));
	printf("%d\n", isprint('\0'));
	printf("%d\n", isprint(127));
	printf("%d\n", isprint(126));

	printf("\n======toupper======\n");
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('1'));
	printf("%c\n", ft_toupper('Z'));
	printf("%c\n", ft_toupper('z'));

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%c\n", toupper('a'));
	printf("%c\n", toupper('1'));
	printf("%c\n", toupper('Z'));
	printf("%c\n", toupper('z'));

	printf("\n======tolower======\n");
	printf("%c\n", ft_tolower('a'));
	printf("%c\n", ft_tolower('1'));
	printf("%c\n", ft_tolower('Z'));
	printf("%c\n", ft_tolower('z'));

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%c\n", tolower('a'));
	printf("%c\n", tolower('1'));
	printf("%c\n", tolower('Z'));
	printf("%c\n", tolower('z'));

	printf("\n======strchr======\n");
	printf("%s\n", ft_strchr(str, 'f'));
	printf("%s\n", ft_strchr(str, '\0'));
	printf("%s\n", ft_strchr(str, 'a'));

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%s\n", strchr(str, 'f'));
	printf("%s\n", strchr(str, '\0'));
	printf("%s\n", strchr(str, 'a'));

	printf("\n=======strdup======\n");
	char *str_src = "I'm Brad";
	char *fr;

	printf("%s\n", fr = ft_strdup(str_src));
	free(fr);

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%s\n", fr = strdup(str_src));
	free(fr);

	printf("\n======calloc======\n");
	int *intarr;
	int *intarr2;

	intarr = ft_calloc(10, sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", intarr[i]);
	}
	free(intarr);
	printf("\n!!!!!!answer!!!!!!\n");
	intarr2 = calloc(10, sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", intarr2[i]);
	}
	free(intarr2);

	printf("\n======substr======\n");
	char *substr = "Hello World this is test";
	printf("%s\n", ft_substr(substr, 0, 3));
	printf("%s\n", ft_substr(substr, 5, 4));
	printf("%s\n", ft_substr(substr, 23, 3));
	printf("%s\n", ft_substr(substr, 24, 3));
	printf("%s\n", ft_substr(substr, -1, 3));

	printf("\n======strjoin======\n");
	char *a = "Hello World";
	char *b = "this is test";
	printf("%s\n", ft_strjoin(a, b));

	printf("\n======strtrim======\n");
	char *trimtest;

	printf("%s\n", trimtest = ft_strtrim("   my name is brad", "a"));
	free(trimtest);
	printf("%s\n", trimtest = ft_strtrim("  my name is brad  ", " m"));
	free(trimtest);
	printf("%s\n", trimtest = ft_strtrim("  my name is brad   ", " "));
	free(trimtest);
	printf("%s\n", trimtest = ft_strtrim("", "a"));
	free(trimtest);
	printf("%s\n", trimtest = ft_strtrim("", ""));
	free(trimtest);

	printf("\n======split======\n");
	char *split_src = "Hello World this   is   test";
	char **res_split;

	res_split = ft_split(split_src, 'e');
	while (*res_split)
	{
		printf("%s\n", *res_split);
		res_split++;
	}

	printf("\n======atoi======\n");
	printf("%d\n", ft_atoi("--1234"));
	printf("%d\n", ft_atoi("   345"));
	printf("%d\n", ft_atoi("\n  \t \r123"));
	printf("%d\n", ft_atoi("-123"));
	printf("%d\n", ft_atoi("+123"));
	printf("%d\n", ft_atoi("+abcde"));
	printf("%d\n", ft_atoi("+111abcde"));
	printf("%d\n", ft_atoi("- 123"));
	printf("%d\n", ft_atoi("+12a3"));
	printf("%d\n", ft_atoi("  \t  -555"));
	printf("%d\n", ft_atoi("  ++111abcde"));

	printf("\n!!!!!!answer!!!!!!\n");
	printf("%d\n", atoi("--1234"));
	printf("%d\n", atoi("   345"));
	printf("%d\n", atoi("\n  \t \r123"));
	printf("%d\n", atoi("-123"));
	printf("%d\n", atoi("+123"));
	printf("%d\n", atoi("+abcde"));
	printf("%d\n", atoi("+111abcde"));
	printf("%d\n", ft_atoi("- 123"));
	printf("%d\n", ft_atoi("+12a3"));
	printf("%d\n", ft_atoi("  \t  -555"));
	printf("%d\n", ft_atoi("  ++111abcde"));

	printf("\n======itoa======\n");
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));
	return (0);
}
