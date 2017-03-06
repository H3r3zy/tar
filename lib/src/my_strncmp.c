/*
** my_strncmp.c for Pool 06 in /home/H3r3zy/rendu/CPool_Day06
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Mon Oct 10 13:25:45 2016 Lucas Sahel
** Last update Fri Feb 17 08:59:10 2017 Sahel
*/

#include "basic.h"

int	strncmp_(char *s1, char *s2, int n)
{
  int	s1_len;
  int	s2_len;
  int	i;

  s1_len = strlen_(s1);
  s2_len = strlen_(s2);
  i = 0;
  if (n < 0)
    n = s1_len;
  while (i < s1_len && i < s2_len && i < n)
    {
      if (s1[i] > s2[i])
	return (s2[i] - s1[i]);
      if (s1[i] < s2[i])
	return (s2[i] - s1[i]);
      i++;
    }
  if (s1_len > s2_len)
    return (s1[i + 1]);
  if (s1_len < s2_len)
    return (-s2[i + 1]);
  return (0);
}
