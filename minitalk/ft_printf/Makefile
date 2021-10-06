CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
INC = .
NAME = libftprintf.a
LIB = ft
LIB_DIR = ./libft

SRCS = ft_printf.c ft_utils.c get_specify.c \
	   ft_utils2.c int_printf.c print_spec.c
BONUS_SRCS = ft_printf_bonus.c ft_utils_bonus.c \
			 get_specify_bonus.c ft_utils2_bonus.c \
			 int_printf_bonus.c print_spec_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(BONUS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(LIB) $(OBJ_FILES)
	cp $(LIB_DIR)/lib$(LIB).a ./$(NAME)
	$(AR) $@ $(OBJ_FILES)

$(LIB):
	@$(MAKE) -C $(LIB_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

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
