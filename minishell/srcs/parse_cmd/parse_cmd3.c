/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:08:08 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:54 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	write_env_val(char **res, char *env_key)
{
	char	*env_val;

	env_val = find_val(env_key);
	if (!env_val)
		return (SUCCESS);
	while (*env_val)
	{
		if (write_str(res, *env_val, 0) != SUCCESS)
			return (parse_err_convert_env(env_key));
		env_val++;
	}
	return (SUCCESS);
}

int	convert_env(char **str_ptr, char **res)
{
	char	*tmp;
	char	*env_key;

	(*str_ptr)++;
	tmp = *str_ptr;
	if (*tmp == '?')
		return (get_recent_status(str_ptr, res));
	while (**str_ptr && !_isspace(**str_ptr) && \
	!is_redi(*str_ptr) && !is_quote(**str_ptr))
		(*str_ptr)++;
	if (tmp == *str_ptr)
		return (only_dollar(res));
	env_key = ft_strndup(tmp, *str_ptr - tmp);
	if (!env_key)
		return (FAIL);
	if (write_env_val(res, env_key) != SUCCESS)
		return (FAIL);
	return (convert_env_return(env_key));
}

int	normal_case(char **str_ptr, char **res)
{
	if (**str_ptr == '$')
	{
		if (convert_env(str_ptr, res) != SUCCESS)
			return (FAIL);
	}
	else
	{
		if (write_str(res, **str_ptr, 0) != SUCCESS)
			return (FAIL);
		(*str_ptr)++;
	}
	return (SUCCESS);
}

int	quote_handle(char **str_ptr, char **res, int quote_flag)
{
	(*str_ptr)++;
	while (**str_ptr && quote_flag != is_quote(**str_ptr))
	{
		if (quote_flag == SMALL_QUOTE)
		{
			if (write_str(res, **str_ptr, 0) != SUCCESS)
				return (FAIL);
			(*str_ptr)++;
		}
		else
		{
			if (normal_case(str_ptr, res) != SUCCESS)
				return (FAIL);
		}
	}
	if (is_quote(**str_ptr))
		(*str_ptr)++;
	else
	{
		errno = EUNCLOSED;
		return (FAIL);
	}
	return (SUCCESS);
}

char	*get_word_move_addr(char **str_ptr)
{
	char	*word;
	int		quote_flag;

	word = 0;
	while (**str_ptr && !_isspace(**str_ptr) && !is_redi(*str_ptr))
	{
		quote_flag = is_quote(**str_ptr);
		if (quote_flag)
		{
			if (quote_handle(str_ptr, &word, quote_flag) != SUCCESS)
				return (parse_err_get_word(word));
		}
		else
		{
			if (normal_case(str_ptr, &word) != SUCCESS)
				return (parse_err_get_word(word));
		}
	}
	if (write_str(&word, 0, 0) != SUCCESS)
		return (parse_err_get_word(word));
	return (word);
}
