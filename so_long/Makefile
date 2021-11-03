CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCHI = -arch x86_64
AR = ar rcs
RM = rm -f
INC = -Iincludes -Ilibmlx -Ilibft
NAME = so_long
LIB_NAME1 = ft
LIB_NAME2 = mlx
LIB = -Llibmlx -Llibft -lmlx -lft -framework OpenGL -framework Appkit
LIB_DIR1 = ./libft
LIB_DIR2 = ./libmlx

SRC_DIR = ./srcs/
BONUS_SRCS_DIR = ./srcs_bonus/
SRC_NAME = main read_map utils\
		map_init map_init2 map_init3 \
		key_operate key_operate2 \
		display display2
BONUS_SRCS = $(addsuffix _bonus.c ,$(addprefix $(BONUS_SRCS_DIR), $(SRC_NAME)))
MANDATORY_SRCS = $(addsuffix .c ,$(addprefix $(SRC_DIR), $(SRC_NAME)))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

ifdef WITH_BONUS
	OBJS = $(BONUS_OBJS)
else
	OBJS = $(MANDATORY_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIB_NAME1) $(LIB_NAME2)
	$(CC) $(CFLAGS) $(ARCHI) $(OBJS) -o $@ $(INC) $(LIB)

$(LIB_NAME1):
	@$(MAKE) -C $(LIB_DIR1) all

$(LIB_NAME2):
	@$(MAKE) -C $(LIB_DIR2) all

%.o: %.c
	$(CC) $(CFLAGS) $(ARCHI) -c $< -o $@ $(INC)

bonus:
	make WITH_BONUS=1 all

clean:
	$(RM) $(MANDATORY_OBJS)
	$(RM) $(BONUS_OBJS)
	@$(MAKE) -C $(LIB_DIR1) clean
	@$(MAKE) -C $(LIB_DIR2) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIB_DIR1) fclean

re: fclean all

.PHONY: all clean fclean re bonus
