SRC=			./aa.cpp \

OBJ=			 $(SRC:.c=.o)

NAME=			 Arbre

CFLAGS=			-Wall -Wextra -Werror -ansi -pedantic

all:			$(NAME)

$(NAME):		$(OBJ)
	gcc -o $(NAME) $(OBJ) -I aa.h

clean:
	rm -f $(OBJ)

fclean:			clean
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
