/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:53:03 by bson              #+#    #+#             */
/*   Updated: 2022/05/27 13:35:49 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define ALLOW_CHAR_SET	"0123456789 ,.+-"

typedef int	t_bool;

# define FALSE (0)
# define TRUE (1)

t_bool	is_empty(char *line);
t_bool	is_next_valid(char *str, int *i);
t_bool	check_line(char *line, int i, char *set);
t_bool	check_range(double n, double min, double max);
double	parsing_one_number(char *str, int *i);
double	ft_atof_idx(const char *str, int *i);
void	parser(char *filename, t_minirt *minirt);
void	parsing_color(t_vec3 *color, char *str, int *i);
void	parsing_position(t_vec3 *pos, char *str, int *i);
void	parsing_normal(t_vec3 *n, char *str, int *i);
void	parsing_ambient(t_minirt *minirt, char *str, int i);
void	parsing_camera(t_minirt *minirt, char *str, int i);
void	parsing_light(t_minirt *minirt, char *str, int i);
void	parsing_sphere(t_minirt *minirt, char *str, int i);
void	parsing_plane(t_minirt *minirt, char *str, int i);
void	parsing_cylinder(t_minirt *minirt, char *str, int i);

#endif
