/*
** debug.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Feb 25 16:20:06 2016 fabrice sepret
** Last update Sat Mar 19 16:01:13 2016 fabrice sepret
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include "tetris.h"

unsigned char	**chang_p(unsigned char **av)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (av[i] != 0)
    {
      if ((my_strcmp_n(av[i], "Size", 4)) == 0)
	{
	  while (av[i][j] != 0)
	    {
	      if (av[i][j] == ',')
		av[i][j] = '*';
	      j += 1;
	    }
	}
      i += 1;
    }
  return (av);
}

int	disp_d(unsigned char **av)
{
  int		i;
  int		j;
  unsigned char	*str;
  unsigned char	*buf;
  int		raw;

  raw = 0;
  i = 0;
  av = chang_p(av);
  while (av[i] != 0)
    {
      my_putstr(av[i]);
      my_putchar('\n');
      i += 1;
    }
  check_t();
  my_putstr("Press a key to start Tetris\n");
  brut(1);
  while (raw == 0)
    {
      raw = read(0, buf, 1);
    }
  brut(0);
  get_line(av);
}
