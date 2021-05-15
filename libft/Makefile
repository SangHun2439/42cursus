CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
INC = includes
TARGET = libft.a
SRCS_DIR = srcs/

SRCS = $(SRCS_DIR)ft_memset.c \
	   $(SRCS_DIR)ft_strrchr.c $(SRCS_DIR)ft_bzero.c \
	   $(SRCS_DIR)ft_strnstr.c $(SRCS_DIR)ft_memcpy.c \
	   $(SRCS_DIR)ft_strncmp.c $(SRCS_DIR)ft_memccpy.c \
	   $(SRCS_DIR)ft_atoi.c $(SRCS_DIR)ft_memmove.c \
	   $(SRCS_DIR)ft_isalpha.c $(SRCS_DIR)ft_memchr.c \
	   $(SRCS_DIR)ft_isdigit.c $(SRCS_DIR)ft_memcmp.c \
	   $(SRCS_DIR)ft_isalnum.c $(SRCS_DIR)ft_strlen.c \
	   $(SRCS_DIR)ft_isascii.c $(SRCS_DIR)ft_strlcpy.c \
	   $(SRCS_DIR)ft_isprint.c $(SRCS_DIR)ft_strlcat.c \
	   $(SRCS_DIR)ft_toupper.c $(SRCS_DIR)ft_strchr.c \
	   $(SRCS_DIR)ft_tolower.c $(SRCS_DIR)ft_strdup.c \
	   $(SRCS_DIR)ft_calloc.c $(SRCS_DIR)ft_substr.c \
	   $(SRCS_DIR)ft_strjoin.c $(SRCS_DIR)ft_strtrim.c \
	   $(SRCS_DIR)ft_split.c $(SRCS_DIR)ft_itoa.c \
	   $(SRCS_DIR)ft_strmapi.c $(SRCS_DIR)ft_putchar_fd.c \
	   $(SRCS_DIR)ft_putstr_fd.c $(SRCS_DIR)ft_putendl_fd.c \
	   $(SRCS_DIR)ft_putnbr_fd.c $(SRCS_DIR)ft_lstnew.c \
	   $(SRCS_DIR)ft_lstadd_front.c $(SRCS_DIR)ft_lstsize.c \
	   $(SRCS_DIR)ft_lstlast.c $(SRCS_DIR)ft_lstadd_back.c \
	   $(SRCS_DIR)ft_lstdelone.c $(SRCS_DIR)ft_lstclear.c \
	   $(SRCS_DIR)ft_lstiter.c $(SRCS_DIR)ft_lstmap.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
