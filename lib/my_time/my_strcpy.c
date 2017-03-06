/*
** my_strcpy.c for PSU_2016_my_ls_bootstrap in /home/sahel/rendu/PSU/PSU_2016_my_ls_bootstrap
**
** Made by Sahel Lucas-Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed Nov 23 23:26:27 2016 Sahel Lucas-Saoudi
** Last update Thu Dec  1 02:46:46 2016 Sahel
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
