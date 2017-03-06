/*
** main.c for  in /home/sahel/rendu/CPE/Rush
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Mar  3 22:01:31 2017 Sahel
** Last update Sun Mar  5 18:51:11 2017 Sahel
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <tar.h>
#include <pwd.h>
#include <dirent.h>
#include <grp.h>
#include "main.h"
#include "basic.h"

int	help(char *bin)
{
  putstr_("Usage: ", 2);
  putstr_(bin, 2);
  putstr_(" [archive_name] [files ...]\n", 2);
  return (84);
}

void	fill(char *s1, char *s2)
{
  int		idx;

  idx = 0;
  while (s2[idx])
    {
      s1[idx] = s2[idx];
      idx++;
    }
}

int		create_file(char *name, int fd_archive, int verbose)
{
  t_file	*file;
  struct dirent	*dirent;
  DIR		*dir;
  int		fd_file;
  char		*new_name;

  if (!(file = malloc(sizeof(t_file))))
    return (MALLOC_FAIL);
  if ((fd_file = open(name, O_RDONLY)) > 2)
    {
      new_file(file, fd_file, strdup(name));
      print_in_header1(fd_archive, file);
      if (file->type_flag[0] == '5' && (dir = opendir(name)))
	{
	  while ((dirent = readdir(dir)))
	    if (!match(dirent->d_name, "..") && !match(dirent->d_name, "."))
	      {
		new_name = strdup(name);
		new_name = concat_free(new_name, "/");
		new_name = concat_free(new_name, dirent->d_name);
		create_file(new_name, fd_archive, verbose);
	      }
	}
    }
  return (0);
}

int		main(int ac, char **av)
{
  char		buffer[1024];
  int		fd_archive;
  int		av_i;

  if (ac < 3)
    return (help(av[0]));
  if ((fd_archive = open(av[1], O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
    return (OPEN_FAIL);
  set_at(buffer, 1024, '\0');
  av_i = 2;
  while (av_i < ac)
    {
      create_file(av[av_i], fd_archive, 0);
      av_i++;
    }
  write(fd_archive, buffer, 1024);
  return (0);
}
