/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:52:56 by bson              #+#    #+#             */
/*   Updated: 2022/05/27 19:20:20 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERROR_H
# define MINIRT_ERROR_H

# define ERROR_NO_ARG			"Scene description file not specified"
# define ERROR_NO_RT_FILE		"No scene description file specified"
# define ERROR_FILE_OPEN		"Failed to open scene description file"
# define ERROR_FILE_READING		"Unable to read scene description file"
# define ERROR_FILE_CLOSE		"Failed to close scene description file"

# define ERROR_INVALID_CHAR		"Only spaces, real numbers, commas, \
and symbols can be used after the identifier."

# define ERROR_UNIQUE			"Identifiers A and C are unique."

# define ERROR_RGB_FORMAT		"Incorrect RGB color formatting"
# define ERROR_VEC_FORMAT		"Incorrect vector formatting"
# define ERROR_NO_IDENT			"Unacceptable identifier"

# define ERROR_OUT_OF_RANGE		"Invalid set value range"
# define ERROR_WRONG_DATA		"Invalid config data"
# define ERROR_WRONG_NUM		"There are numbers that cannot be read."

void		ft_error(char *error_detail);
void		*ft_calloc_assert(size_t count, size_t size);

#endif
