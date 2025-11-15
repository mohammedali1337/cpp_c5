CC = c++ -Wall -Wextra -Werror -std=c++98
NAME = Bureaucrat
SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all clean
	clear
	./$(NAME)
	