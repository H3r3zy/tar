/*
** my_putchar.c for Lib in /home/H3r3zy/rendu/CPool_Day07/lib/my
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Tue Oct 11 11:31:28 2016 Lucas Sahel
** Last update Sat Mar  4 02:47:55 2017 Sahel
*/

#include <unistd.h>

void	putchar_(char c, int fd)
{
  write(fd, &c, 1);
}
