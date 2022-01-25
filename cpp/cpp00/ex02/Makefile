CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
RM = rm -f
INC =
SRC_DIR = ./srcs/
SRC_NAME = Account tests
SRCS = $(addsuffix .cpp, $(addprefix $(SRC_DIR), $(SRC_NAME)))
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
