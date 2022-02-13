CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = karen
RM = rm -f
INC = -I.
SRC_DIR = ./
SRC_NAME = main Karen
SRCS = $(addsuffix .cpp, $(addprefix $(SRC_DIR), $(SRC_NAME)))
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(INC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
