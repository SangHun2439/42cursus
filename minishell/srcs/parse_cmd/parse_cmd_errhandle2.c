/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_errhandle2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 08:49:56 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:32 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_err_redi(t_redi *redi)
{
	put_errmsg();
	free(redi);
	return (FAIL);
}

int	mem_err_redi2(t_redi *redi)
{
	put_errmsg();
	free(redi->arg);
	free(redi);
	return (FAIL);
}

char	*parse_err_get_word(char *str)
{
	write_str(0, 0, 1);
	if (str)
		free(str);
	put_errmsg();
	return (0);
}

int	parse_err_convert_env(char *str)
{
	free(str);
	return (FAIL);
}

int	convert_env_return(char *str)
{
	free(str);
	return (0);
}
