SRC			= main.cpp ClapTrap.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= claptrap
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
HDERS		=  ClapTrap.hpp

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