/*
** my_strdup.c for PSU_2016_my_ls_bootstrap in /home/sahel/rendu/PSU/PSU_2016_my_ls_bootstrap
**
** Made by Sahel Lucas-Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed Nov 23 23:25:12 2016 Sahel Lucas-Saoudi
** Last update Thu Dec  1 00:16:52 2016 Sahel
*/

#include <stdlib.h>
#include "my_time.h"

char	*my_strdup(char *src)
{
  char	*dest;

  dest = malloc(sizeof(char) * my_strlen(src) + 1);
  dest = my_strcpy(dest, src);
  return (dest);
}
