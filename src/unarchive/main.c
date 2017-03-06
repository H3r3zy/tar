/*
** main.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar  4 21:03:30 2017 Sahel
** Last update Sun Mar  5 19:28:07 2017 Sahel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "main.h"
#include "basic.h"

static int	help(char *bin)
{
  printf("Usage: %s [archive_name]\n", bin);
  return (84);
}

int	main(int ac, char **av)
{
  int	fd;

  if (ac != 2)
    return (help(av[0]));
  fd = open(av[1], O_RDONLY);
  if (fd < 0)
    return (OPEN_FAIL);
  make_file(fd, 0);
  return (0);
}
