/*
** get_time.c for PSU_2016_my_ls_bootstrap in /home/sahel/rendu/PSU/PSU_2016_my_ls_bootstrap
**
** Made by Sahel Lucas-Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Thu Nov 24 16:59:44 2016 Sahel Lucas-Saoudi
** Last update Sun Mar  5 22:27:04 2017 Sahel
*/

#include <stdlib.h>
#include <string.h>
#include "my_time.h"
#include "basic.h"

void		define_time(t_my_time *time)
{
  time->sec = 0;
  time->min = 0;
  time->hour = 0;
  time->day = 1;
  time->sem = 0;
  time->nbmonth = 1;
  time->month = strdup("Jan");
  time->year = 1970;
}

void		define_rac_month(char **tab)
{
  tab[1] = strdup("Jan");
  tab[2] = strdup("Fev");
  tab[3] = strdup("Mar");
  tab[4] = strdup("Apr");
  tab[5] = strdup("May");
  tab[6] = strdup("Jun");
  tab[7] = strdup("Jul");
  tab[8] = strdup("Aug");
  tab[9] = strdup("Sep");
  tab[10] = strdup("Oct");
  tab[11] = strdup("Nov");
  tab[12] = strdup("Dec");
  tab[13] = NULL;
}

void		define_month(int *month, char **rac_month, t_my_time *time)
{
  month[1] = 31;
  month[2] = 29;
  month[3] = 31;
  month[4] = 30;
  month[5] = 31;
  month[6] = 30;
  month[7] = 31;
  month[8] = 31;
  month[9] = 30;
  month[10] = 31;
  month[11] = 30;
  month[12] = 31;
  define_rac_month(rac_month);
  define_time(time);
}

t_my_time	*get_time(long long int sec)
{
  t_my_time	*time;
  int		month[13];
  char		*rac_month[14];

  time = malloc(sizeof(t_my_time));
  define_month(month, rac_month, time);
  time->sec = sec % 60;
  time->min = sec / 60 % 60;
  time->hour = sec / 60 / 60 % 24 + 1;
  time->day = sec / 60 / 60 / 24 + 1;
  while (time->day > month[time->nbmonth])
    {
      if (time->nbmonth == 2 && time->year % 4 != 0)
	time->day -= 28;
      else
	time->day -= month[time->nbmonth];
      time->nbmonth += 1;
      if (time->nbmonth > 12)
	{
	  time->nbmonth = 1;
	  time->year += 1;
	}
    }
  time->month = rac_month[time->nbmonth];
  return (time);
}
