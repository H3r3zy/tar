/*
** set_header.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sun Mar  5 14:00:03 2017 Sahel
** Last update Sun Mar  5 14:01:41 2017 Sahel
*/

#include "main.h"

void	set_header(t_header *header)
{
  set_at(header->name, 100, '\0');
  set_at(header->perm, 8, '\0');
  set_at(header->uid, 8, '\0');
  set_at(header->gid, 8, '\0');
  set_at(header->size, 12, '\0');
  set_at(header->mtime, 12, '\0');
  set_at(header->chcksum, 8, '\0');
  set_at(header->type_flag, 1, '\0');
  set_at(header->link_name, 100, '\0');
  set_at(header->magic, 6, '\0');
  set_at(header->version, 2, '\0');
  set_at(header->uname, 32, '\0');
  set_at(header->gname, 32, '\0');
  set_at(header->devmajor, 8, '\0');
  set_at(header->devminor, 8, '\0');
  set_at(header->prefix, 155, '\0');
}
