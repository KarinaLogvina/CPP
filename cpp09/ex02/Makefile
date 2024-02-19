NAME = PmergeMe

CXX = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = @rm -rf

INCLUDES =	PmergeMe.hpp

SRCS =		main.cpp PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS) $(INCLUDES) Makefile
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\nupdated"

%.o: %.cpp $(INCLUDES) Makefile
	$(CXX) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)
	@echo "\nclean done"

fclean :
	$(RM) $(OBJS)
	$(RM) $(NAME)
	@echo "\nfclean done"

re : fclean all

# val : all
# 	valgrind --leak-check=full ./$(NAME)

.PHONY : all clean fclean re