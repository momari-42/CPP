SRC			= main.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= easyfind
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror 
HDERS		= easyfind.hpp

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