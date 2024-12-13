SRC			= main.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= mutated
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror 
HDERS		= MutantStack.hpp

all : $(NAME)

$(NAME): $(OBJ) 
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HDERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)