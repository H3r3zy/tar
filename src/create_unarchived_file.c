/*
** create_unarchived_file.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sun Mar  5 14:05:15 2017 Sahel
** Last update Sun Mar  5 19:26:33 2017 Sahel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include "basic.h"

int		create_dir(char *path)
{
  char		*newpath;
  char		*dirname;
  struct stat	st;

  if (!(newpath = malloc(strlen(path))) ||
      check_slash(path) == (int) strlen(path))
    return (-1);
  newpath = strdup(path);
  while (check_slash(newpath) != (int) strlen(newpath))
    {
      dirname = only_before(newpath, '/');
      newpath = without_before_(newpath, '/');
      printf("%s\n", dirname);
      if (lstat(dirname, &st) == -1)
	mkdir(dirname, 0755);
      dirname = concat_free(dirname, "/");
    }
  return (0);
}

void		print_in_unarchived(t_header *header, int fd)
{
  char		*file;
  mode_t	perm;
  int		fd2;
  int		size;

  size = b_to_d(atoi(header->size), 8);
  if (!(file = malloc(sizeof(char) * size + 512)))
    return ;
  perm = b_to_d(atoi(header->perm), 8) | take_type(header->type_flag);
  fd2 = open(header->name, O_CREAT | O_TRUNC | O_RDWR, perm);
  if (fd2 < 0)
    if ((fd2 = create_dir(header->name)) == -1)
      return ;
  size = read(fd, file, size);
  if (size > 0)
    {
      write(fd2, file, size);
      size = size % 512;
      size = 512 - size;
      read(fd, file, size);
      free(file);
    }
  else
    read(fd, file, 512);
}

int		check(int checksum, t_header *header)
{
  checksum -= add_ascii(header->name, 100);
  checksum -= add_ascii(header->perm, 8);
  checksum -= add_ascii(header->uid, 8);
  checksum -= add_ascii(header->gid, 8);
  checksum -= add_ascii(header->size, 12);
  checksum -= add_ascii(header->mtime, 12);
  checksum -= add_ascii("        ", 8);
  checksum -= add_ascii(header->type_flag, 1);
  checksum -= add_ascii(header->link_name, 100);
  checksum -= add_ascii(header->magic, 6);
  checksum -= add_ascii(header->version, 2);
  checksum -= add_ascii(header->uname, 32);
  checksum -= add_ascii(header->gname, 32);
  checksum -= add_ascii(header->devmajor, 8);
  checksum -= add_ascii(header->devminor, 8);
  checksum -= add_ascii(header->prefix, 8);
  return (checksum);
}

int		coru(t_header *header)
{
  fprintf(stderr, "%s: Header corrupted\n", header->name);
  return (1);
}

void		make_file(int fd, int verbose)
{
  int		size;
  char		inter_header[512];
  t_header	*header;

  header = malloc(sizeof(t_header));
  size = read(fd, header, sizeof(t_header));
  if (size < 0 || match(header->name, "\0\0\0*"))
    return ;
  if (check(b_to_d(atoi(header->chcksum), 8), header) != 0 && coru(header))
    return ;
  if (match(header->name, "*PaxHeaders.*"))
    {
      size = read(fd, &inter_header, 512);
      size = read(fd, header, sizeof(t_header));
      if (check(b_to_d(atoi(header->chcksum), 8), header) != 0 && coru(header))
	return ;
    }
  if (verbose)
    printf("%s\n", header->name);
  if (header->type_flag[0] != '5')
    print_in_unarchived(header, fd);
  else
    mkdir(header->name, 0755);
  make_file(fd, verbose);
}
