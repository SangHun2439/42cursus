CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
INC = -I. -I./libft
NAME = push_swap
LIB = ft
LIB_DIR = ./libft

SRCS = main.c ft_deq_isempty.c ft_deq_newnode.c ft_deqadd_back.c \
		ft_deqadd_front.c ft_deqclear.c ft_deqget_back.c \
		ft_deqget_front.c ft_deqinit.c ft_deqpop_back.c \
		ft_deqpop_front.c ft_utils.c ft_swap.c \
		ft_push.c ft_rotate.c ft_revrotate.c
BONUS_SRCS =
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(BONUS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(LIB) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@ $(INC) -L$(LIB_DIR) -l$(LIB)

$(LIB):
	@$(MAKE) -C $(LIB_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

bonus:
	make WITH_BONUS=1 all

clean:
	$(RM) $(OBJ_FILES)
	$(RM) $(BONUS_OBJS)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
