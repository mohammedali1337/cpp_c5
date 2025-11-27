CXX			= c++
CXX_F		= -Wall -Wextra -Werror -std=c++98
NAME        = Identify_real_type
SRCS        = A.cpp B.cpp Base.cpp C.cpp functions.cpp main.cpp
OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_F) $(OBJS) -o $(NAME)

%.o: %.cpp A.hpp B.hpp Base.hpp C.hpp functions.hpp
	 	$(CXX) $(CXX_F) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
