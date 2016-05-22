/*
** game.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Mon Mar  7 15:20:11 2016 fabrice sepret
** Last update Sat Mar 19 16:29:44 2016 fabrice sepret
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

unsigned char	*my_tet(unsigned char *av, unsigned char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (av[i] != '\n')
    i += 1;
  i += 1;
  while (av[i] != 0)
    {
      str[j] = av[i];
      j += 1;
      i += 1;
    }
  return (str);
}

int		my_tetrimi(unsigned char **av, unsigned char **param)
{
  unsigned int	i;
  unsigned char	**str;
  unsigned char	*test;

  i = 0;
  if ((str = malloc(sizeof(char **) * 50000)) == NULL)
    exit(-1);
  while (av[i] != 0)
    {
      if ((str[i] = malloc(sizeof(char *) * 100000)) == NULL)
	exit(-1);
      if ((test = my_cat(my_strcat("tetriminos/", av[i]), 10)) != NULL)
	str[i] = my_tet(my_cat(my_strcat("tetriminos/", av[i]), 10), str[i]);
      i += 1;
    }
  get_size_m(str, param, param[9]);
  free(str);
}

int		get_tetrimi(unsigned char **param)
{
  struct dirent	*str;
  DIR		*rep;
  unsigned char	**tet;
  int		i;

  if ((tet = malloc(sizeof(char **) * (1000))) == NULL)
    exit(-1);
  i = 0;
  if ((rep = opendir("tetriminos")) == NULL)
    {
      my_putstr_er("Error: repository ''tetriminos'' not found\n");
      exit(-1);
    }
  while ((str = readdir(rep)) != NULL)
    if (tetrimi(str->d_name) != NULL)
      tet[i++] = tetrimi(str->d_name);
  my_tetrimi(tet, param);
}
