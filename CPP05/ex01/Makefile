CXX 	= c++
CXX_F	= -Wall -Wextra -Werror -std=c++98
NAME 	= Form
SRCS 	= main.cpp Bureaucrat.cpp Form.cpp
OBJS 	= $(SRCS:.cpp=.o)
RM 		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_F) $(OBJS) -o $(NAME)

%.o : %.cpp Form.hpp Bureaucrat.hpp
	$(CXX) $(CXX_F) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
