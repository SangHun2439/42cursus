CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = -Iincludes
NAME = philo

SRC_DIR = ./srcs/
SRC_NAME = main utils init \
			error end_error_deal end_error_deal2 end_error_deal3\
			free_struct philo_routine monitoring
SRCS = $(addsuffix .c ,$(addprefix $(SRC_DIR), $(SRC_NAME)))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(ARCHI) $(OBJS) -o $@ $(INC)

%.o: %.c
	$(CC) $(CFLAGS) $(ARCHI) -c $< -o $@ $(INC)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
