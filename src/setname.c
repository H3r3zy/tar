/*
** setname.c for  in /home/sahel/rendu/CPE/Rush
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar  4 13:37:52 2017 Sahel
** Last update Sun Mar  5 14:26:05 2017 Sahel
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

void	add_char(char *name, int *name_i, char *str, int len)
{
  int	str_i;

  str_i = 0;
  while (str_i <= len)
    {
      name[*name_i] = str[str_i];
      (*name_i)++;
      str_i++;
    }
}

void		set_headername(char *hname, char *name, t_file *file)
{
  int		hname_i;
  char		*str = "PaxHeaders.";
  char		nb[255];

  hname_i = 0;
  if (check_slash(name) == (int) strlen(name))
    {
      hname[0] = '.';
      hname[1] = '/';
      hname_i = 2;
    }
  while (check_slash(name) != (int) strlen(name))
    {
      add_char(hname, &hname_i, name, check_slash(name));
      name = without_before_(name, '/');
    }
  add_char(hname, &hname_i, str, strlen(str) - 1);
  sprintf(nb, "%d", file->pid);
  add_char(hname, &hname_i, nb, strlen(nb) - 1);
  hname[hname_i++] = '/';
  add_char(hname, &hname_i, name, strlen(name) - 1);
}
