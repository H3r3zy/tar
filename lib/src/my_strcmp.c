/*
** my_strcmp.c for Pool 06 in /home/H3r3zy/rendu/CPool_Day06
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Mon Oct 10 13:05:19 2016 Lucas Sahel
** Last update Fri Feb 17 08:29:43 2017 Sahel
*/

#include "basic.h"

int	strcmp_(char *s1, char *s2)
{
  int	s1_len;
  int	s2_len;
  int	i;

  s1_len = strlen_(s1);
  s2_len = strlen_(s2);
  i = 0;
  while (i == s1_len && i == s2_len)
    {
      if (s1[i] > s2[i])
	return (1);
      if (s1[i] < s2[i])
	return (-1);
      i++;
    }
  if (s1_len > s2_len)
    return (1);
  if (s1_len < s2_len)
    return (-1);
  return (0);
}
