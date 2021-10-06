CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
INC = -I. -I./ft_printf -I./ft_printf/libft
NAME1 = server
NAME2 = client
LIB = ftprintf
LIB_DIR = ./ft_printf

SRCS1 = server.c
SRCS2 = client.c
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(LIB) $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o $@ $(INC) -L$(LIB_DIR) -l$(LIB)

$(NAME2): $(LIB) $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $@ $(INC) -L$(LIB_DIR) -l$(LIB)

$(LIB):
	@$(MAKE) -C $(LIB_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

bonus:
	make all

clean:
	$(RM) $(OBJS1) $(OBJS2)
	$(RM) $(BONUS_OBJS)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME1) $(NAME2)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
