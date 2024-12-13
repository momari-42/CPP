SRC			= main.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= template
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
HDERS		= Array.hpp Array.tpp

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