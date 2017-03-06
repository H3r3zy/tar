/*
** create_file.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sun Mar  5 18:23:26 2017 Sahel
** Last update Sun Mar  5 19:31:14 2017 Sahel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include "main.h"
#include "basic.h"

int		create_file(char *name, int fd_archive, int verbose)
{
  t_file        *file;
  struct dirent *dirent;
  DIR           *dir;
  int           fd_file;
  char          *new_name;

  if (!(file = malloc(sizeof(t_file))))
    return (84);
  if ((fd_file = open(name, O_RDONLY)) > 2)
    {
      new_file(file, fd_file, strdup(name));
      if (verbose)
	printf("%s\n", name);
      print_in_header1(fd_archive, file);
      if (file->type_flag[0] == '5' && (dir = opendir(name)))
	while ((dirent = readdir(dir)))
	  if (!match(dirent->d_name, "..") && !match(dirent->d_name, "."))
	    {
	      new_name = concat_free(strdup(name), "/");
	      new_name = concat_free(new_name, dirent->d_name);
	      create_file(new_name, fd_archive, verbose);
	    }
    }
  return (0);
}
