CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
INC = -I. -I./libft
NAME = push_swap
BONUS_NAME = checker
LIB = ft
LIB_DIR = ./libft

SRCS = main.c ft_deq_isempty.c ft_deq_newnode.c ft_deqadd_back.c \
		ft_deqadd_front.c ft_deqclear.c ft_deqget_back.c \
		ft_deqget_front.c ft_deqinit.c ft_deqpop_back.c \
		ft_deqpop_front.c ft_utils.c ft_swap.c \
		ft_push.c ft_rotate.c ft_revrotate.c \
		ft_deqget_idx.c quick_sort.c \
		input.c ft_deq_count.c quick_select.c \
		quick_sort2.c hard_sort.c
BONUS_SRCS = ft_deq_isempty.c ft_deq_newnode.c ft_deqadd_back.c \
		ft_deqadd_front.c ft_deqclear.c ft_deqget_back.c \
		ft_deqget_front.c ft_deqinit.c ft_deqpop_back.c \
		ft_deqpop_front.c ft_utils.c ft_swap.c \
		ft_push.c ft_rotate.c ft_revrotate.c \
		ft_deqget_idx.c input.c \
		main_bonus.c get_next_line_bonus.c checker_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) -L$(LIB_DIR) -l$(LIB)

$(BONUS_NAME): $(LIB) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $@ $(INC) -L$(LIB_DIR) -l$(LIB)

$(LIB):
	@$(MAKE) -C $(LIB_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

bonus: $(NAME) $(BONUS_NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
