CXX			= c++
CXX_F		= -Wall -Wextra -Werror -std=c++98
NAME        = Array
SRCS        = main.cpp
OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_F) $(OBJS) -o $(NAME)

%.o: %.c Array.hpp
	 	$(CXX) $(CXX_F) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
