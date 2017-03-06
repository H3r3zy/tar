##
## Makefile for  in /home/sahel/bin/lib
## 
## Made by Sahel
## Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
## 
## Started on  Fri Feb 17 08:01:04 2017 Sahel
## Last update Sat Mar  4 17:18:05 2017 Sahel
##

SRC		=	src/my_strlen.c		\
			src/my_strdup.c		\
			src/tabdup_.c		\
			src/free_.c		\
			src/sp_len_.c		\
			src/my_strcpy.c		\
			src/match.c		\
			src/my_getnbr.c		\
			src/my_putchar.c	\
			src/my_putstr.c		\
			src/puttab_.c		\
			src/my_putnbr.c		\
			src/power.c		\
			src/my_strcat.c		\
			src/my_strcpy.c		\
			src/my_strcat.c		\
			src/my_strncat.c	\
			src/my_strstr.c		\
			src/my_strcmp.c		\
			src/my_is_prime.c	\
			src/sqrt.c		\
			src/tablen_.c

OBJ		=	$(SRC:.c=.o)

NAME		=	libbasic.a

CFLAGS		=	-Wall -Wextra -I.

INCLUDEDIR	=	../include/

MY_H_NAME	=	basic.h

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(MY_H_NAME) $(INCLUDEDIR)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
