SRC			= tests.cpp Account.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= account
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
HDERS		= Account.hpp

all : $(NAME)

$(NAME): $(OBJ)  $(HDERS)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)