SRC			= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= human
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
HDERS		= HumanA.hpp HumanB.hpp Weapon.hpp

all : $(NAME)

$(NAME): $(OBJ) $(HDERS)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)