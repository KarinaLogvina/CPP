NAME = AAnimal
CPP = c++
FLAGS = -Wall -Werror -Wextra
STD = -std=c++98
SRCS = main.cpp Cat.cpp Dog.cpp AAnimal.cpp Brain.cpp

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

re: fclean all