##
## Makefile for  in /home/sahel/rendu/PSU/PSU_2016_my_ls_bootstrap/lib/my_time
## 
## Made by Sahel
## Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
## 
## Started on  Thu Dec  1 00:00:47 2016 Sahel
## Last update Thu Dec  1 00:42:59 2016 Sahel
##

SRC		=	get_time.c	\
			my_strlen.c	\
			my_strdup.c	\
			my_strcpy.c

OBJ		=	$(SRC:.c=.o)

NAME		=	libmy_time.a

INCLUDEDIR	=	../../Include/

MY_H_NAME	=	my_time.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(MY_H_NAME) $(INCLUDEDIR)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
