CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
ARCHI = -arch x86_64
AR = ar rcs
RM = rm -f
INC = -I. -Imlx -Ilibft
NAME = so_long
LIB_NAME = ft mlx
LIB = -Lmlx -Llibft -lmlx -lft -framework OpenGL -framework Appkit
LIB_DIR = ./libft

SRCS = main.c map_render.c read_map.c \
		utils.c key_operate.c key_operate2.c \
		map_render2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) $(ARCHI) $(OBJS) -o $@ $(INC) $(LIB)

$(LIB_NAME):
	@$(MAKE) -C $(LIB_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) $(ARCHI) -c $< -o $@ $(INC)

bonus:
	make all

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
