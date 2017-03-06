/*
** my_time.h for  in /home/sahel/rendu/PSU/PSU_2016_my_ls_bootstrap/lib/my_time
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Thu Dec  1 00:11:30 2016 Sahel
** Last update Thu Dec  1 00:23:58 2016 Sahel
*/

#ifndef MY_TIME_H_
# define MY_TIME_H_

struct		s_my_time
{
  char		sec;
  char		min;
  char		hour;
  int		day;
  int		sem;
  int		nbmonth;
  char		*month;
  int		year;
};

typedef struct s_my_time	t_my_time;
int				my_strlen(char *);
char				*my_strdup(char *);
char				*my_strcpy(char *, char *);
t_my_time			*get_time(long long int);

#endif /* !MY_TIME_H_ */
