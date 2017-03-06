/*
** fill.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sun Mar  5 18:31:06 2017 Sahel
** Last update Sun Mar  5 18:31:10 2017 Sahel
*/

void    fill(char *s1, char *s2)
{
  int           idx;

  idx = 0;
  while (s2[idx])
    {
      s1[idx] = s2[idx];
      idx++;
    }
}
