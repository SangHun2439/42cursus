/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:24:40 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/21 11:24:07 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "read_cmd.h"
# include "libft.h"
# include "my_perr.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <limits.h>

typedef struct s_env
{
	char	*key;
	char	*val;
	int		flag;
}	t_env;

typedef struct s_cmd
{
	char	**argv;
	t_list	*redi_list;
}	t_cmd;

typedef struct s_redi
{
	char	redi_status;
	char	*arg;
}	t_redi;

typedef struct s_vars
{
	int		last_status;
	int		heredoc_exit;
	t_list	*env_list;
}	t_vars;

t_vars	g_vars;

# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define FAIL 1

# define EXIST 0
# define NOT_EXIST 1

# define PWD_BUF_SIZE 200

# define NOCMD 127
# define RPIPE 0
# define WPIPE 1
# define NODO 777

# define REDIRECT_INPUT 1
# define REDIRECT_OUTPUT 2
# define REDIRECT_HEREDOC 3
# define REDIRECT_APPEND 4

# define PARSE_CMD_BUF_SIZE 200
# define BIG_QUOTE 1
# define SMALL_QUOTE 2

# define EMPTYLINE -1

/* main */
void	init_err(void);
int		init(char **argv, t_list **cmd_list_ptr, char **envp);
void	del_cmd(void *content);
void	free_split(char **str_arr);
void	heredoc_sigint_handler(int sig);
void	sig_handler(int sig);
char	*ft_strndup(const char *s1, size_t max);
void	*err_handle3(void);
char	*find_val(char *str);
int		is_key(char *str);
char	**format_envp(void);
void	del_env_one(void *content);
/* main */

/* exec_cmd */
int		redirect(t_list *redi_list);
int		redirect_append(char *arg);
int		redirect_heredoc(char *arg);
int		redirect_input(char *arg);
int		redirect_output(char *arg);
int		exec_cmd(t_list *cmd_list);
int		exec_ft(t_cmd *cmd, char **path);
char	*get_full_path(char *each_cmd, char *each_path);
int		get_child_return(pid_t pid);
int		parents_do(pid_t pid, char *full_path);
int		file_exist(char *path);
void	getback_fd_std(int fd_stdout, int fd_stdin);
void	save_fd_std(int *fd_stdout, int *fd_stdin);
int		end_exec_ft(int res, int fd_stdout, int fd_stdin);
int		end_redirect_err(void);
int		execve_err(void);
int		is_path(char *str, char **argv);
int		fork_err(char *full_path);
int		child_do(char *full_path, char **argv, char **envp);
int		exec_builtin(t_cmd *cmd);
void	errno_print(int error, char *str);
int		exec_pipe(t_list *cmd_list, char **path);
int		parents_do_pipe(pid_t pid, int **pipe_arr);
int		exec_util_pipe(t_cmd *cmd, char **path);
void	is_path_pipe(char *str, char **argv);
void	child_do_pipe(t_cmd *cmd, char **path, int **pipe_arr, int num);
int		execve_err_pipe(void);
int		**pipe_init_alloc_err(int **pipe_arr, int end);
int		**pipe_init_err(int **pipe_arr, int end);
void	exit_path(char *str);
/* exec_cmd */

/* parser */
int		parse_cmd(t_list **cmd_list_ptr, char *line);
int		_isspace(char chr);
int		is_redi(const char *str);
void	redi_move_ptr(char **line_ptr, int redi_status);
char	**list_to_arr(t_list *list);
int		list_clear(t_list **cmd_line_list_ptr, t_list **redi_list_ptr);
void	del_redi_one(void *content);
int		parse_err_redi(t_redi *redi);
int		mem_err_redi2(t_redi *redi);
int		fill_cmd_redi_list(char **one_cmd_ptr, \
t_list	**cmd_line_list_ptr, t_list **redi_list_ptr);
int		parse_init(char **line_ptr, char ***cmd_arr_ptr);
int		case_cmd(char **one_cmd_ptr, t_list **cmd_line_list_ptr);
int		case_redi(char **one_cmd_ptr, t_list **redi_list_ptr, int redi_status);
char	*get_word_move_addr(char **str_ptr);
int		parse_err(void);
int		parse_err_cmd(char **cmd_arr, int res);
int		parse_err_mem2(char **cmd_arr, t_cmd *cmd);
int		parse_err_mem3(t_list **cmd_line_list, t_list **redi_list);
int		parse_unexpected_err(void);
int		is_quote(char c);
int		write_str(char **res, char c, int clear_flag);
char	*unclosedquotes_err(char *str);
char	*parse_err_get_word(char *str);
int		parse_err_convert_env(char *str);
int		convert_env_return(char *str);
int		only_dollar(char **res);
int		get_recent_status(char **str_ptr, char **res);
int		write_tmp_file(t_redi *redi);
int		heredoc_err_mem(char *arg);
int		heredoc_err_fd(char *fname, char *arg);
int		heredoc_err_sigint(char *fname);
int		is_sep(char c);
char	**split_cmd(char *cmd);
void	quote_check(int *flag_ptr, char c);
/* parser */

/* builtin */
int		ft_echo(t_cmd *cmd);
int		ft_env(t_cmd *cmd);
int		ft_exit(t_cmd *cmd);
int		ft_export(t_cmd *cmd);
int		ft_pwd(void);
int		ft_unset(t_cmd *cmd);
int		ft_cd(t_cmd *cmd);
int		is_valid_str(char *str);
void	env_overriding(char *str, int *cnt);
int		is_direc(char *path);
int		ft_cd_err(int error, char *dir);
int		length_to_equ(const char *str);
int		export_no_parm(void);
char	*cut_val(char *str);
int		ft_home_not_set(void);
/* builtin */

#endif
