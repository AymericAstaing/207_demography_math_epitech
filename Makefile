##
## EPITECH PROJECT, 2018
## 204ducks Math Project
## File description:
## Makefile of 204duck
##

CC			=	g++

NAME		=	207demography

SRC_PATH	=	src/

CFLAGS		=	-Wall -Wextra -Werror -I./include -g2 -lm

SRC			=	main.cpp

SRC			+=	$(SRC_PATH)Country.cpp			\
				$(SRC_PATH)Utils.cpp			\
				$(SRC_PATH)Demo.cpp

OBJ			=	$(SRC:.c=.o)


$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

all:				$(NAME)


clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:
	fclean re clean