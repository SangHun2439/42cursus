CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = convert
RM = rm -f
INC = -I.
SRC_DIR = ./
SRC_NAME = main \
			Convert \
			Detect \
			CharConvert \
			IntConvert \
			FloatConvert \
			DoubleConvert

SRCS = $(addsuffix .cpp, $(addprefix $(SRC_DIR), $(SRC_NAME)))
OBJS = $(SRCS:.cpp=.o)

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(INC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC)

debug:
	$(MAKE) DEBUG=1

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
