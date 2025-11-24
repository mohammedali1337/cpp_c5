C++         = c++
C++FLAGS    = -Wall -Wextra -Werror -std=c++98
NAME        = convert
SRCS        = main.cpp ScalarConverter.cpp
OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re