/*
** main.h for  in /home/sahel/rendu/CPE/Rush
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar  4 02:48:38 2017 Sahel
** Last update Sun Mar  5 22:35:17 2017 Sahel
*/

#ifndef MAIN_H_
# define MAIN_H_

# define MALLOC_FAIL	84
# define OPEN_FAIL	84

typedef struct	s_file{
  int		fd;
  int		pid;
  char		headername[100];
  char		filename[100];
  char		mode[8];
  char		uid[8];
  char		gid[8];
  char		size[12];
  char		between[512];
  char		omtime[12];
  char		mtime[12];
  char		mtimen[12];
  char		atime[12];
  char		atimen[12];
  char		ctime[12];
  char		ctimen[12];
  char		chksum[8];
  char		chksum2[8];
  char		type_flag[1];
  char		link_name[100];
  char		magic[6];
  char		version[2];
  char		uname[32];
  char		gname[32];
  char		devmajor[8];
  char		devminor[8];
  char		prefix[155];
}		t_file;

typedef struct	s_header
{
  char		name[100];
  char		perm[8];
  char		uid[8];
  char		gid[8];
  char		size[12];
  char		mtime[12];
  char		chcksum[8];
  char		type_flag[1];
  char		link_name[100];
  char		magic[6];
  char		version[2];
  char		uname[32];
  char		gname[32];
  char		devmajor[8];
  char		devminor[8];
  char		prefix[155];
  char		useless[12];
}		t_header;

char		*without_before_(char *, char);
char		*only_before(char *, char);
char		*concat_free(char *, char *);
void		print_in_header1(int, t_file *);
void		set_at(char *, int, char);
void		new_file(t_file *, int, char *);
void		fill(char *, char *);
void		set_headername(char *, char *, t_file *);
void		set_header(t_header *);
void		make_file(int, int);
void		list(int, int);
int		create_file(char *, int, int);
int		checksum(int, t_file *);
int		add_ascii(char *, int);
int		check_slash(char *);
int		take_type(char *);
long int	b_to_d(long int, int);
int		check(int, t_header *);
int		coru(t_header *);

#endif /* !MAIN_H_ */
