/*
** change_lvl.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Wed Feb 24 16:24:25 2016 fabrice sepret
** Last update Sat Mar 19 16:00:54 2016 fabrice sepret
*/

#include <stdlib.h>
#include "tetris.h"

unsigned char	**change_lvl(unsigned char *av, unsigned char **param)
{
  if (av == NULL || av[0] == '-')
    {
      my_putstr_er("./tetris : missing operand\n");
      my_putstr_er("try './tetris --help' for more information.\n");
      exit(-1);
    }
  param[8] = "Level : ";
  param[8] = my_strcat(param[8], av);
  return (param);
}

unsigned char	**m_change_lvl(unsigned char **param, unsigned char *av)
{
  int		i;
  int		j;
  unsigned char	*str;

  i = 0;
  j = 0;
  if ((str = malloc(sizeof(char *) * my_strlen(av))) == NULL)
    exit (-1);
  while (av[i] != 0)
    {
      if (av[i] >= '1' && av[i] <= '9')
	{
	  str[j] = av[i];
	  j += 1;
	}
      i += 1;
    }
  param[8] = "Level : ";
  param[8] = my_strcat(param[8], str);
  free(str);
  return (param);
}
