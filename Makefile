##
## Makefile for  in /home/sahel/rendu/CPE/Rush
## 
## Made by Sahel
## Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
## 
## Started on  Fri Mar  3 21:33:24 2017 Sahel
## Last update Sun Mar  5 22:24:44 2017 Sahel
##

SRC	=	src/main.c			\
		src/without_before_.c		\
		src/only_before.c		\
		src/print_in.c			\
		src/new_file.c			\
		src/setname.c			\
		src/chcksum.c			\
		src/concat.c			\
		src/set_at.c			\
		src/add_ascii.c			\
		src/slash.c			\
		src/set_header.c		\
		src/create_unarchived_file.c	\
		src/create_file.c		\
		src/fill.c			\
		src/b_to_d.c			\
		src/list.c

SRCARCH	=	src/archive/main.c		\
		src/without_before_.c		\
		src/print_in.c			\
		src/new_file.c			\
		src/setname.c			\
		src/chcksum.c			\
		src/concat.c			\
		src/set_at.c			\
		src/add_ascii.c			\
		src/slash.c

SRCNARC	=	src/unarchive/main.c		\
		src/set_at.c			\
		src/set_header.c		\
		src/create_unarchived_file.c	\
		src/add_ascii.c			\
		src/only_before.c		\
		src/without_before_.c		\
		src/slash.c			\
		src/concat.c			\
		src/b_to_d.c

SRCLIB	=	lib/src/my_strlen.c		\
                lib/src/my_strdup.c		\
                lib/src/tabdup_.c		\
                lib/src/free_.c			\
                lib/src/sp_len_.c		\
                lib/src/match.c			\
                lib/src/my_getnbr.c		\
                lib/src/my_putchar.c		\
                lib/src/my_putstr.c		\
                lib/src/puttab_.c		\
                lib/src/my_putnbr.c		\
                lib/src/power.c			\
                lib/src/my_strcpy.c		\
                lib/src/my_strcat.c		\
                lib/src/my_strncat.c		\
                lib/src/my_strstr.c		\
                lib/src/my_strcmp.c		\
                lib/src/my_is_prime.c		\
                lib/src/sqrt.c			\
                lib/src/tablen_.c		\
		lib/my_time/get_time.c

OBJ	=	$(SRC:.c=.o)

OBJLIB	=	$(SRCLIB:.c=.o)

OBJARCH	=	$(SRCARCH:.c=.o)

OBJNARC	=	$(SRCNARC:.c=.o)

CFLAGS	=	-Wall -Wextra -Iinclude -g

NAME	=	my_tar

all:	$(NAME)

$(NAME):	 $(OBJLIB) $(OBJ) $(OBJARCH) $(OBJNARC)
	gcc -o $(NAME) $(OBJLIB) $(OBJ)
	gcc -o my_archive $(OBJLIB) $(OBJARCH)
	gcc -o my_unarchive $(OBJLIB) $(OBJNARC)

clean:
	rm -rf $(OBJ) $(OBJLIB) $(OBJARCH) $(OBJNARC)

fclean: clean
	rm -rf $(NAME) my_archive my_unarchive

re: fclean all
