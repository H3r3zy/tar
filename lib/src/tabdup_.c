/*
** tabdup_.c for  in /home/sahel/rendu
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Feb 25 17:11:14 2017 Sahel
** Last update Sat Feb 25 17:13:29 2017 Sahel
*/

#include <stdlib.h>
#include "basic.h"

char	**tabdup_(char **tab)
{
  char	**new_tab;
  int	tab_i;

  if (!tab || !(new_tab = malloc(sizeof(char *) * (tablen_(tab) + 1))))
    return (NULL);
  tab_i = 0;
  while (tab[tab_i])
    {
      new_tab[tab_i] = strdup_(tab[tab_i]);
      tab_i++;
    }
  new_tab[tab_i] = NULL;
  return (new_tab);
}
