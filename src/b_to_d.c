/*
** b_to_d.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sun Mar  5 18:34:43 2017 Sahel
** Last update Sun Mar  5 22:35:35 2017 Sahel
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"
#include "basic.h"

long int	b_to_d(long int nb, int base)
{
  long int	dec;
  int		rang;

  rang = 0;
  dec = 0;
  while (nb != 0)
    {
      dec += nb % 10 * power_(base, rang);
      rang++;
      nb = nb / 10;
    }
  return (dec);
}

int		take_type(char *type)
{
  if (type[0] == '0')
    return (S_IFREG);
  if (type[0] == '2')
    return (S_IFLNK);
  if (type[0] == '3')
    return (S_IFCHR);
  if (type[0] == '4')
    return (S_IFBLK);
  if (type[0] == '5')
    return (S_IFDIR);
  if (type[0] == '6')
    return (S_IFIFO);
  if (type[0] == '7')
    return (S_IFSOCK);
  return (S_IFREG);
}
