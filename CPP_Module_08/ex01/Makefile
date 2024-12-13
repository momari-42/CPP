SRC			= main.cpp Span.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= span
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror
HDERS		= Span.hpp

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