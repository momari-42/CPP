SRC			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= fragtrap
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
HDERS		=  ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

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