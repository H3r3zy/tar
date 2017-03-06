/*
** only_before.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sun Mar  5 15:45:20 2017 Sahel
** Last update Sun Mar  5 19:30:09 2017 Sahel
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

char		*only_before(char *str, char c)
{
  int		str_i;
  char		*new;

  if (!(new = malloc(strlen(str))))
    return (NULL);
  str_i = 0;
  while (str && str[str_i] && str[str_i] != c)
    {
      new[str_i] = str[str_i];
      str_i++;
    }
  return (new);
}
