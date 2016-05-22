/*
** my_cat.c for  in /home/sepret_f/progelem/bsq/e2
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Wed Dec 30 12:18:26 2015 fabrice sepret
** Last update Sat Mar 19 16:10:17 2016 fabrice sepret
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

int		xread(const int fd, unsigned char *buffer, int size)
{
  int		nb_read;

  if ((nb_read = read(fd, buffer, size)) == -1)
    {
      my_putstr("Read Failed\n");
      my_putstr("Usage : ./bsq [map] -> [map] need ");
      my_putstr("to be store in a file\n");
      exit(-1);
    }
  return (nb_read);
}

unsigned char	*my_cat(unsigned char *av1, int j)
{
  struct stat	*buf;
  int		i;
  int		fd;
  unsigned char	*buffer;

  i = 0;
  if ((buf = malloc(sizeof(*buf))) == NULL
      || stat(av1, buf) == -1
      || (buffer = malloc(buf->st_size)) == NULL
      || (fd = open(av1, O_RDONLY)) == -1)
    return (NULL);
  if ((i = xread(fd, buffer, buf->st_size)) == 0 && j == 10)
    return (NULL);
  else
    return (buffer);
}
