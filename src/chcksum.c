/*
** chcksum.c for  in /home/sahel/rendu/CPE/Rush
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar  4 14:10:22 2017 Sahel
** Last update Sun Mar  5 15:31:49 2017 Sahel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

static int	checksum_header2(t_file *file)
{
  int		cksum;

  cksum = 0;
  cksum += add_ascii(file->filename, 100);
  cksum += add_ascii(file->mode, 8);
  cksum += add_ascii(file->uid, 8);
  cksum += add_ascii(file->gid, 8);
  cksum += add_ascii(file->size, 12);
  cksum += add_ascii(file->omtime, 12);
  cksum += add_ascii(file->type_flag, 1);
  cksum += add_ascii("        ", 8);
  cksum += add_ascii(file->magic, 6);
  cksum += add_ascii(file->version, 2);
  cksum += add_ascii(file->uname, 32);
  cksum += add_ascii(file->gname, 32);
  cksum += add_ascii(file->devmajor, 8);
  cksum += add_ascii(file->devminor, 8);
  return (cksum);
}

int		checksum(int which, t_file *file)
{
  int		cksum;

  cksum = 0;
  if (which == 1)
    {
      cksum += add_ascii(file->headername, 100);
      cksum += add_ascii("0000644", 7);
      cksum += add_ascii("00000000000000", 14);
      cksum += add_ascii("00000000132", 11);
      cksum += add_ascii(file->omtime, 12);
      cksum += add_ascii("        x", 9);
      cksum += add_ascii(file->magic, 6);
      cksum += add_ascii(file->version, 2);
      return (cksum);
    }
  else
    return (checksum_header2(file));
}
