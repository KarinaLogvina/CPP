NAME = Intern
CPP = c++
FLAGS = -Wall -Werror -Wextra
STD = -std=c++98
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

.cpp.o:
	@c++ ${FLAGS}  -c $< -o ${<:.cpp=.o}
OBJS = ${SRCS:.cpp=.o}

all: $(NAME)
$(NAME):$(OBJS)
		$(CPP) $(FLAGS) $(STD) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

val : all
	valgrind --leak-check=full ./$(NAME)

re: fclean all

