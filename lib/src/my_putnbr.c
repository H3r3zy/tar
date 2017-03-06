/*
** my_putnbr.c for  in /home/sahel/bin/lib/src
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Feb 17 08:14:40 2017 Sahel
** Last update Sat Mar  4 02:48:27 2017 Sahel
*/

#include "basic.h"

static void	print_number(long int nb, int fd)
{
  if (nb >= 1)
    {
      print_number((nb / 10), fd);
      putchar_((nb % 10) + 48, fd);
    }
}

void		putnbr_(int nb, int fd)
{
  long int	long_nb;

  long_nb = nb;
  if (long_nb < 0)
    {
      putchar_('-', fd);
      print_number((long_nb * -1), fd);
    }
  else if (long_nb == 0)
    putchar_(long_nb + 48, fd);
  else
    print_number(long_nb, fd);
}
