SRC			= main.cpp Contact.cpp PhoneBook.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= phonebook
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
HDERS		= Contact.hpp PhoneBook.hpp

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