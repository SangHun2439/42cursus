CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
ARCHI		= -arch x86_64
RM			= rm -f
RMR			= rm -rf
NAME		= miniRT
LIB_NAME1	= ft
LIB_NAME2	= mlx
LIB_NAME3	= gnl
LIB_DIR1	= ./libft
LIB_DIR2	= ./libmlx
LIB_DIR3	= ./libgnl
INC			= -I./includes/ -I$(LIB_DIR2) -I$(LIB_DIR1) -I$(LIB_DIR3)
LIB			= -L$(LIB_DIR1) -L$(LIB_DIR2) -L$(LIB_DIR3) -l$(LIB_NAME1) -l$(LIB_NAME2) -l$(LIB_NAME3) -framework OpenGL -framework Appkit

SRC_DIR		= ./srcs/
OBJ_DIR		= ./objs/

DIR_PARS	=	parsing/

SRC_NAME = main \
			$(DIR_PARS)parser \
			$(DIR_PARS)parsing_unique \
			$(DIR_PARS)parsing_common \
			$(DIR_PARS)parsing_utils \
			$(DIR_PARS)parsing_utils2 \
			$(DIR_PARS)check_range \
			$(DIR_PARS)ft_atof_idx \
			$(DIR_PARS)occur_error \
			$(DIR_PARS)view_list \
			$(DIR_PARS)view_minirt \
			$(DIR_PARS)view_obj \
			$(DIR_PARS)view_vec3 \
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

SRCS		=	$(addsuffix .c ,$(addprefix $(SRC_DIR), $(SRC_NAME)))
OBJ_LIST	=	$(SRC_NAME:.c=.o)
OBJS		=	$(addsuffix .o ,$(addprefix $(OBJ_DIR), $(OBJ_LIST)))

ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
	mkdir $(OBJ_DIR) 2> /dev/null || true
	mkdir $(OBJ_DIR)$(DIR_PARS) 2> /dev/null || true
	$(CC) $(CFLAGS) $(ARCHI) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR1) all
	$(MAKE) -C $(LIB_DIR2) all
	$(MAKE) -C $(LIB_DIR3) all
	$(CC) $(CFLAGS) $(ARCHI) $(OBJS) -o $@ $(INC) $(LIB)

all: $(NAME)

debug:
	$(MAKE) DEBUG=1

clean:
	@$(MAKE) -C $(LIB_DIR1) clean
	@$(MAKE) -C $(LIB_DIR2) clean
	@$(MAKE) -C $(LIB_DIR3) clean
	$(RMR) $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIB_DIR1) fclean
	@$(MAKE) -C $(LIB_DIR3) fclean
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re bonus
