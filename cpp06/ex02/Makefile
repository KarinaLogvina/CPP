NAME = base

CXX = clang

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = @rm -rf

INCLUDES =	Base.hpp \
			A.hpp	 \
			B.hpp 	 \
			C.hpp 	 \
			func.hpp

SRCS =		Base.cpp	\
			func.cpp 	\
			main.cpp	\

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS) $(INCLUDES) Makefile
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\nconvert updated"

%.o: %.cpp $(INCLUDES) Makefile
	$(CXX) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)
	@echo "\nconvert clean done"

fclean :
	$(RM) $(OBJS)
	$(RM) $(NAME)
	@echo "\nconvert fclean done"

re : fclean all

# val : all
# 	valgrind --leak-check=full ./$(NAME)

.PHONY : all clean fclean re