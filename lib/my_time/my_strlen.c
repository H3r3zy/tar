/*
** error.c for  in /home/sahel/rendu/PSU/PSU_2016_my_ls_bootstrap
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Tue Nov 22 14:04:46 2016 Sahel
** Last update Wed Nov 23 10:45:23 2016 Sahel
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
