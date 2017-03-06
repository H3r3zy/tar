/*
** concat.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar  4 18:03:51 2017 Sahel
** Last update Sun Mar  5 14:25:01 2017 Sahel
*/

#include <stdlib.h>
#include <unistd.h>
#include "basic.h"

char	*concat_free(char *str1, char *str2)
{
  char	*new;
  int	str_i[2];

  if (str1 && str2)
    new = malloc(strlen_(str1) + strlen_(str2) + 1);
  else
    new = malloc(strlen_((str1) ? (str1) : (str2)) + 1);
  if (!new)
    return (NULL);
  str_i[0] = 0;
  str_i[1] = 0;
  while (str1 && str1[str_i[0]])
    {
      new[str_i[0]] = str1[str_i[0]];
      str_i[0]++;
    }
  while (str2 && str2[str_i[1]])
    {
      new[str_i[0] + str_i[1]] = str2[str_i[1]];
      str_i[1]++;
    }
  new[str_i[0] + str_i[1]] = '\0';
  free_(str1);
  return (new);
}

