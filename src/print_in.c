/*
** print_in.c for  in /home/sahel/rendu/CPE/Rush
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar  4 11:54:45 2017 Sahel
** Last update Sun Mar  5 16:24:36 2017 Sahel
*/

#include <unistd.h>
#include <stdlib.h>
#include "main.h"

static void	perte_de_memoire(int fd, int l_block)
{
  char		buffer[512];

  set_at(buffer, 512, '\0');
  l_block = l_block % 512;
  l_block = 512 - l_block;
  write(fd, buffer, l_block);
}

static void	print_in_file(int fd, t_file *file)
{
  char		*buffer;
  int		size;

  if (!(buffer = malloc(sizeof(char) * atoi(file->size) + 1)))
    return ;
  size = read(file->fd, buffer, atoi(file->size));
  if (size <= 0)
    return ;
  write(fd, buffer, size);
  perte_de_memoire(fd, size);
}

static void	print_in_header3(int fd, t_file *file)
{
  write(fd, file->filename, 100);
  write(fd, file->mode, 8);
  write(fd, file->uid, 8);
  write(fd, file->gid, 8);
  write(fd, file->size, 12);
  write(fd, file->omtime, 12);
  write(fd, file->chksum2, 6);
  write(fd, "\0 ", 2);
  write(fd, file->type_flag, 1);
  write(fd, file->link_name, 100);
  write(fd, file->magic, 6);
  write(fd, file->version, 2);
  write(fd, file->uname, 32);
  write(fd, file->gname, 32);
  write(fd, file->devmajor, 8);
  write(fd, file->devminor, 8);
  write(fd, file->prefix, 155);
  write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0", 12);
}

void	print_in_header1(int fd, t_file *file)
{
  write(fd, file->headername, 100);
  write(fd, "0000644\0", 8);
  write(fd, "0000000\0000000000\00000000000132\0", 28);
  write(fd, file->omtime, 12);
  write(fd, file->chksum, 6);
  write(fd, "\0 x", 3);
  write(fd, file->link_name, 100);
  write(fd, file->magic, 6);
  write(fd, file->version, 2);
  write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
  write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
  write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
  write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
  write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
  write(fd, file->prefix, 155);
  write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0", 12);
  write(fd, file->between, 512);
  print_in_header3(fd, file);
  print_in_file(fd, file);
}
