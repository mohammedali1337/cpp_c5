CC = c++ -Wall -Wextra -Werror -std=c++98
NAME = AForm
SRCS = AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp main.cpp 

OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.cpp AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all clean
	clear
	./$(NAME)