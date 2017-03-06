/*
** set_at.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar  4 21:25:35 2017 Sahel
** Last update Sun Mar  5 14:26:24 2017 Sahel
*/

void	set_at(char *str, int len, char c)
{
  int	str_i;

  str_i = 0;
  while (str_i < len)
    {
      str[str_i] = c;
      str_i++;
    }
}
