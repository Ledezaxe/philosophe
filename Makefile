##
## Makefile for  in /home/rouane_q/projets/unix/philosophe
## 
## Made by quentin rouanet
## Login   <rouane_q@epitech.net>
## 
## Started on  Mon Mar 17 10:20:44 2014 quentin rouanet
## Last update Tue Mar 18 17:02:08 2014 quentin rouanet
##

NAME	= philo

SRCS	= main.c \
	  philo.c

OBJ	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

ECHO	= @echo -e

CFLAGS	+= -W -Wall -Wextra
CFLAGS	+= -Werror
##CFLAGS	+= -ansi -pedantic
##CFLAGS	+= -I.

LIBTHREAD	= -pthread

all	: $(NAME)

$(NAME)	: $(OBJ)
	  $(CC) -o $(NAME) $(OBJ) $(LIBTHREAD)
	  $(ECHO) '\033[0;32m> Compiled\033[0m'

clean	:
	  $(RM) $(OBJ)
	  $(RM) *~
	  $(RM) \#*#
	  $(ECHO) '\033[0;31m> Directory cleaned\033[0m'

fclean	: clean
	  $(RM) $(NAME)
	  $(ECHO) '\033[0;31m> Remove executable\033[0m'

re	: fclean all

.PHONY	: all clean fclean re

