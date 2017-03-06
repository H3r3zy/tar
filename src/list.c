/*
** list.c for  in /home/sahel/rendu/CPE/CPE_2016_b2rush1
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sun Mar  5 21:35:37 2017 Sahel
** Last update Sun Mar  5 22:38:12 2017 Sahel
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include "basic.h"
#include "my_time.h"

void		skip_end(int fd, t_header *header)
{
  int		size;
  char		*buffer;

  size = b_to_d(atoi(header->size), 8);
  if (!(buffer = malloc(sizeof(char) * size + 512)))
    return ;
  size = read(fd, buffer, size);
  if (size > 0)
    {
      size = size % 512;
      size = 512 - size;
      read(fd, buffer, size);
      free(buffer);
    }
}

void            print_perm(long int permission)
{
  printf((permission & S_IRUSR) ? "r" : "-");
  printf((permission & S_IWUSR) ? "w" : "-");
  printf((permission & S_IXUSR) ? "x" : "-");
  printf((permission & S_IRGRP) ? "r" : "-");
  printf((permission & S_IWGRP) ? "w" : "-");
  printf((permission & S_IXGRP) ? "x" : "-");
  printf((permission & S_IROTH) ? "r" : "-");
  printf((permission & S_IWOTH) ? "w" : "-");
  if (permission & S_ISVTX)
    if (permission & S_IXOTH)
      printf("t");
    else
      printf("T");
  else
    printf((permission & S_IXOTH) ? "x" : "-");
  printf(" ");
}

void		verb(t_header *header)
{
  t_my_time	*time;

  time = malloc(sizeof(t_my_time));
  if (header->type_flag[0] == '0')
    printf("-");
  if (header->type_flag[0] == '2')
    printf("l");
  if (header->type_flag[0] == '3')
    printf("c");
  if (header->type_flag[0] == '4')
    printf("b");
  if (header->type_flag[0] == '5')
    printf("d");
  if (header->type_flag[0] == '6')
    printf("l");
  if (header->type_flag[0] == '7')
    printf("s");
  print_perm(b_to_d(atoi(header->perm), 8));
  time = get_time(b_to_d(atol(header->mtime), 8));
  printf(" %s/%s %i %i-%02i-%02i %02i:%02i ", header->uname, header->gname,
	 (int) b_to_d(atoi(header->size), 8), time->year, time->nbmonth,
	 time->day, time->hour, time->sec);
}

void		list(int fd, int verbose)
{
  int		size;
  char		inter_header[512];
  t_header	*header;

  header = malloc(sizeof(t_header));
  if (fd < 0 || (isatty(0) == 1 && fd == 0))
    return ;
  size = read(fd, header, sizeof(t_header));
  if (size < 0 || match(header->name, "\0\0\0*"))
    return ;
  if (check(b_to_d(atoi(header->chcksum), 8), header) != 0 && coru(header))
    return ;
  if (match(header->name, "*PaxHeaders.*"))
    {
      size = read(fd, &inter_header, 512);
      size = read(fd, header, sizeof(t_header));
      if (check(b_to_d(atoi(header->chcksum), 8), header) != 0 && coru(header))
        return ;
    }
  if (verbose)
    verb(header);
  printf("%s\n", header->name);
  skip_end(fd, header);
  list(fd, verbose);
}
