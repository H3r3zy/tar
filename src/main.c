/*
** main.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sun Mar  5 14:15:05 2017 Sahel
** Last update Sun Mar  5 21:55:19 2017 Sahel
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
#include "basic.h"

typedef struct	s_option
{
  int		x;
  int		c;
  int		f;
  int		v;
  int		t;
  int		p;
  int		validity;
}		t_option;

t_option	set_flag(t_option flag)
{
  flag.validity = 1;
  flag.x = 0;
  flag.c = 0;
  flag.t = 0;
  flag.p = 0;
  flag.f = 0;
  flag.v = 0;
  return (flag);
}

t_option	valid_flag(char *str)
{
  int		str_i;
  t_option	flag;

  str_i = 0;
  flag = set_flag(flag);
  while (str && str[str_i])
    {
      if (str[str_i] == 'x')
	flag.x++;
      else if (str[str_i] == 'c')
	flag.c++;
      else if (str[str_i] == 'f')
	flag.f++;
      else if (str[str_i] == 'v')
	flag.v++;
      else if (str[str_i] == 't')
	flag.t++;
      else if (str[str_i] == 'p')
	flag.p++;
      else if (str[str_i] != '-' && str_i != 0)
	flag.validity = 0;
      str_i++;
    }
  return (flag);
}

int		check_flag(t_option flag, char *bin, char **av)
{
  if ((flag.t == 1 && flag.f == 0 && isatty(0) == 1) ||
      (flag.x == 1 && flag.f == 0) || (flag.c == 1 && flag.f == 0))
    {
      fprintf(stderr, "%s: Refusing to read archive contents", bin);
      fprintf(stderr, "from terminal (missing -f otion?)\n");
      fprintf(stderr, "%s: Error is not recoveravle exiting now\n", bin);
      return (84);
    }
  if (flag.c == 1 && flag.f == 1 && tablen_(av) < 4)
    {
      fprintf(stderr, "%s: Cowardly refusing to create empty archive\n", bin);
      return (84);
    }
  if (flag.x == 1 && flag.f == 1 && tablen_(av) != 3)
    {
      fprintf(stderr, "%s: Old option 'f' requires an argument.\n", bin);
      return (84);
    }
  if ((flag.x == 1 && flag.c == 1) || (flag.x == 1 && flag.t == 1) ||
      (flag.c == 1 && flag.t == 1))
    {
      fprintf(stderr, "%s: You may not specity more than one option\n", bin);
      return (84);
    }
  return (0);
}

void		compile(int ac, char **av, t_option flag)
{
  char		buffer[1024];
  int		fd_archive;
  int		av_i;

  if ((fd_archive = open(av[2], O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
    return ;
  set_at(buffer, 1024, '\0');
  av_i = 3;
  while (av_i < ac)
    {
      create_file(av[av_i], fd_archive, flag.v);
      av_i++;
    }
  write(fd_archive, buffer, 1024);
}

int		main(int ac, char **av)
{
  t_option	flag;
  int		fd;

  if (ac < 2)
    {
      fprintf(stderr, "%s: You must specify one of the option", av[0]);
      return (84);
    }
  flag = valid_flag(av[1]);
  if (check_flag(flag, av[0], av) == 84)
    return (84);
  if (flag.c == 1)
    compile(ac, av, flag);
  fd = open(av[2], O_RDONLY);
  if (flag.x == 1 && fd > 0)
    make_file(fd, flag.v);
  if (flag.t == 1)
    list((flag.f == 0) ? (0) : (fd), flag.v);
  return (0);
}
