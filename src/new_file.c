/*
** new_file.c for  in /home/sahel/rendu/CPE/Rush
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar  4 13:11:34 2017 Sahel
** Last update Sun Mar  5 19:17:07 2017 Sahel
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <string.h>
#include <tar.h>
#include <pwd.h>
#include <grp.h>
#include "main.h"

static void	init_file3(t_file *file, struct stat buf)
{
  sprintf(file->omtime, "%lo", buf.st_mtim.tv_sec);
  sprintf(file->mtime, "%li", buf.st_mtim.tv_sec);
  sprintf(file->mtimen, "%li", buf.st_mtim.tv_nsec);
  sprintf(file->atime, "%li", buf.st_atim.tv_sec);
  sprintf(file->atimen, "%li", buf.st_atim.tv_nsec);
  sprintf(file->ctime, "%li", buf.st_ctim.tv_sec);
  sprintf(file->ctimen, "%li", buf.st_ctim.tv_nsec);
  sprintf(file->between, "%li mtime=%s.%s\n%li atime=%s.%s\n%li ctime=%s.%s\n",
          strlen(file->mtime) + strlen(file->mtimen) + 11,
	  file->mtime, file->mtimen, strlen(file->atime) +
	  strlen(file->atimen) + 11, file->atime, file->atimen,
          strlen(file->ctime) + strlen(file->ctimen) + 11,
	  file->ctime, file->ctimen);
  sprintf(file->chksum, "%06o", checksum(1, file));
  sprintf(file->chksum2, "%06o", checksum(2, file));
}

static void	init_file2(t_file *file, struct stat buf)
{
  sprintf(file->magic, "%s", TMAGIC);
  sprintf(file->version, "%s", TVERSION);
  sprintf(file->uname, "%s", getpwuid(buf.st_uid)->pw_name);
  sprintf(file->gname, "%s", getgrgid(buf.st_gid)->gr_name);
  if (file->type_flag[0] == '3' || file->type_flag[0] == '4')
    {
      sprintf(file->devmajor, "%07i", major(buf.st_dev));
      sprintf(file->devminor, "%07i", minor(buf.st_dev));
    }
  else
    {
      sprintf(file->devmajor, "%07i", 0000000);
      sprintf(file->devminor, "%07i", 0000000);
    }
  if (file->type_flag[0] == '5' || file->type_flag[0] == '2')
    sprintf(file->size, "%011o", 00000000000);
  else
    sprintf(file->size, "%011lo", buf.st_size);
  init_file3(file, buf);
}

static void	init_file(t_file *file, char *name,
			  struct stat buf)
{
  fill(file->filename, name);
  set_headername(file->headername, name, file);
  sprintf(file->mode, "%07o", buf.st_mode);
  file->mode[0] = '0';
  file->mode[1] = '0';
  file->mode[2] = '0';
  file->mode[3] = '0';
  sprintf(file->uid, "%07o", buf.st_uid);
  sprintf(file->gid, "%07o", buf.st_gid);
  sprintf(file->mtime, "%011lo", buf.st_mtim.tv_sec);
  if ((buf.st_mode & S_IFMT) == S_IFREG)
    file->type_flag[0] = '0';
  else if ((buf.st_mode & S_IFMT) == S_IFBLK)
    file->type_flag[0] = '4';
  else if ((buf.st_mode & S_IFMT) == S_IFDIR)
    file->type_flag[0] = '5';
  else if ((buf.st_mode & S_IFMT) == S_IFCHR)
    file->type_flag[0] = '3';
  else if ((buf.st_mode & S_IFMT) == S_IFLNK)
    file->type_flag[0] = '2';
  else if ((buf.st_mode & S_IFMT) == S_IFIFO)
    file->type_flag[0] = '6';
  else if ((buf.st_mode & S_IFMT) == S_IFSOCK)
    file->type_flag[0] = '7';
  init_file2(file, buf);
}

static void	new_file2(t_file *file, char *name, struct stat buf)
{
  set_at(file->uname, 32, '\0');
  set_at(file->gname, 32, '\0');
  set_at(file->devmajor, 8, '\0');
  set_at(file->devminor, 8, '\0');
  set_at(file->size, 12, '\0');
  set_at(file->prefix, 155, '\0');
  set_at(file->between, 512, '\0');
  set_at(file->mtime, 12, '\0');
  set_at(file->mtimen, 12, '\0');
  set_at(file->atime, 12, '\0');
  set_at(file->atimen, 12, '\0');
  set_at(file->ctime, 12, '\0');
  set_at(file->ctimen, 12, '\0');
  set_at(file->omtime, 12, '\0');
  set_at(file->chksum, 8, '\0');
  set_at(file->chksum2, 8, '\0');
  init_file(file, name, buf);
}

void		new_file(t_file *file, int fd, char *name)
{
  struct stat	buf;

  lstat(name, &buf);
  file->fd = fd;
  file->pid = getpid();
  set_at(file->filename, 100, '\0');
  set_at(file->headername, 100, '\0');
  set_at(file->mode, 8, '\0');
  set_at(file->uid, 8, '\0');
  set_at(file->gid, 8, '\0');
  set_at(file->mtime, 12, '\0');
  set_at(file->type_flag, 1, '\0');
  set_at(file->link_name, 100, '\0');
  set_at(file->magic, 6, '\0');
  set_at(file->version, 2, '\0');
  new_file2(file, name, buf);
}
