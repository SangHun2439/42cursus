CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCHI = -arch x86_64
RM = rm -f
INC = -Iincludes -Ilibmlx -Ilibft -Ilibgnl
NAME = miniRT
LIB_NAME1 = ft
LIB_NAME2 = mlx
LIB_NAME3 = gnl
LIB_DIR1 = ./libft
LIB_DIR2 = ./libmlx
LIB_DIR3 = ./libgnl
LIB = -L$(LIB_DIR1) -L$(LIB_DIR2) -L$(LIB_DIR3) -l$(LIB_NAME1) -l$(LIB_NAME2) -l$(LIB_NAME3) -framework OpenGL -framework Appkit

SRC_DIR = ./srcs/
SRC_NAME = main \
			init \
			init2 \
			init3 \
			camera_ray \
			cylinder \
			plane \
			sphere \
			ray_trace \
			ray \
			setcolor \
			utils \
			utils2 \
			vec3f \
			vec3f2 \
			vec3f3 \
			event_operate
SRCS = $(addsuffix .c ,$(addprefix $(SRC_DIR), $(SRC_NAME)))
OBJS = $(SRCS:.c=.o)

ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIB_NAME1) $(LIB_NAME2) $(LIB_NAME3)
	$(CC) $(CFLAGS) $(ARCHI) $(OBJS) -o $@ $(INC) $(LIB)

$(LIB_NAME1):
	@$(MAKE) -C $(LIB_DIR1) all

$(LIB_NAME2):
	@$(MAKE) -C $(LIB_DIR2) all

$(LIB_NAME3):
	@$(MAKE) -C $(LIB_DIR3) all

%.o: %.c
	$(CC) $(CFLAGS) $(ARCHI) -c $< -o $@ $(INC)

debug:
	$(MAKE) DEBUG=1

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIB_DIR1) clean
	@$(MAKE) -C $(LIB_DIR2) clean
	@$(MAKE) -C $(LIB_DIR3) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIB_DIR1) fclean
	@$(MAKE) -C $(LIB_DIR3) fclean


re: fclean all

.PHONY: all clean fclean re bonus
