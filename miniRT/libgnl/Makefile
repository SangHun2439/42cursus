CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCHI = -arch x86_64
AR = ar rcs
RM = rm -f
INC = .
NAME = libgnl.a
SRCS_DIR = ./
SRCS_NAME = get_next_line get_next_line_utils

SRCS = $(addsuffix .c ,$(addprefix $(SRCS_DIR), $(SRCS_NAME)))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(ARCHI) $(CFLAGS) -c $< -o $@ -I $(INC)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
