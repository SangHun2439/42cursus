CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
INC = .
NAME = libftprintf.a
LIB = libft.a
LIB_DIR = libft

SRCS = ft_printf.c ft_utils.c get_specify.c
BONUS_SRCS =
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(BONUS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $@ $^

$(LIB):
	cd libft; make

bonus:
	make WITH_BONUS=1 all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
