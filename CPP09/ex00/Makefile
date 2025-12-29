CXX			= c++
CXX_F		= -Wall -Wextra -Werror -std=c++98
NAME        = btc
SRCS        = main.cpp BitcoinExchange.cpp
OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_F) $(OBJS) -o $(NAME)

%.o: %.cpp BitcoinExchange.hpp
	 	$(CXX) $(CXX_F) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
