CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = -Iincludes -Ilibft
LIB_NAME = ft
LIB_DIR = ./libft
LIB = -Llibft -lft -lreadline
NAME = minishell

UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
	UNAME_M := $(shell uname -m)
	ifeq ($(UNAME_M),x86_64)
		CFLAGS	+= -Igoinfre/.brew/opt/readline/include
		LIB		+= -Lgoinfre/.brew/opt/readline/lib
	endif
	ifeq ($(UNAME_M),arm64)
		CFLAGS	+= -I/opt/homebrew/opt/readline/include
		LIB		+= -L/opt/homebrew/opt/readline/lib
	endif
endif

SRC_DIR = ./srcs/
SRC_NAME = main \
main_end \
read_cmd \
sig_handler \
format_envp \
init \
utils \
my_perr \
parse_cmd/parse_cmd \
parse_cmd/parse_cmd2 \
parse_cmd/parse_cmd3 \
parse_cmd/parse_cmd_utils \
parse_cmd/parse_cmd_utils2 \
parse_cmd/parse_cmd_utils3 \
parse_cmd/parse_cmd_utils4 \
parse_cmd/parse_cmd_errhandle \
parse_cmd/parse_cmd_errhandle2 \
parse_cmd/parse_cmd_errhandle3 \
exec_cmd/exec_cmd \
exec_cmd/exec_cmd2 \
exec_cmd/exec_cmd_utils \
exec_cmd/exec_cmd_redi \
exec_cmd/exec_cmd_end \
exec_cmd/exec_cmd_end2 \
exec_cmd/exec_cmd_pipe \
exec_cmd/exec_cmd_pipe2 \
builtin/ft_echo \
builtin/ft_pwd \
builtin/ft_export \
builtin/ft_env \
builtin/ft_exit \
builtin/ft_unset \
builtin/ft_cd	\
builtin/builtin_utils \
builtin/env_utils

SRCS = $(addsuffix .c ,$(addprefix $(SRC_DIR), $(SRC_NAME)))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIB_NAME):
	@$(MAKE) -C $(LIB_DIR) all

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
