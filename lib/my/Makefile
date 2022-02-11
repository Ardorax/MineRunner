##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## my first Makefile
##

CC = gcc
EXEC = libmy.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(EXEC)

libmy.a : $(OBJ)
	@$(CC) -c *.c
	@ar rc $@ *.o

%.o : %.c
	@$(CC) -c $<

clean :
	@rm -f *.o

fclean : clean
	@rm -f $(EXEC)
