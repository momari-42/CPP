SRC			= main.cpp contact.cpp phonebook.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= phonebook
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
HDERS		= contact.hpp phonebook.hpp

all : $(NAME)

$(NAME): $(OBJ)  $(HDERS)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)