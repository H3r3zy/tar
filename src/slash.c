/*
** slash.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sun Mar  5 16:04:03 2017 Sahel
** Last update Sun Mar  5 19:28:54 2017 Sahel
*/

int	check_slash(char *str)
{
  int	str_i;

  str_i = 0;
  while (str && str[str_i] && str[str_i] != '/')
    {
      str_i++;
    }
  return (str_i);
}
