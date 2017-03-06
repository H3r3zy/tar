/*
** add_ascii.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sun Mar  5 15:31:58 2017 Sahel
** Last update Sun Mar  5 19:20:15 2017 Sahel
*/

int		add_ascii(char *str, int limit)
{
  int		len;
  int		nb;

  len = 0;
  nb = 0;
  while (str[len] && len < limit)
    {
      nb += str[len];
      len++;
    }
  return (nb);
}
