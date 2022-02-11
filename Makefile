##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## launch the program
##

SRC = $(wildcard ./sources/*.c) $(wildcard ./start/*.c) \
$(wildcard ./obstacles/*.c)

OBJ = $(SRC:.c=.o)

NAME = my_runner

FLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C ./lib/my
	@gcc $(SRC) -o $(NAME) -Llib/my -lmy -g3 -I./include/ $(FLAGS) -lm

clean:
	@make -s clean -C ./lib/my
	@rm -f $(OBJ)

fclean:	clean
	@make -s fclean -C ./lib/my
	@rm -f $(NAME)

re: fclean all
