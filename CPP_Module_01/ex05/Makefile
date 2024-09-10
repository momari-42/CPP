SRC			= main.cpp Harl.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= harl
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
HDERS		= Harl.hpp

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