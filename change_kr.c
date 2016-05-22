/*
** change_kr.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Feb 25 15:47:25 2016 fabrice sepret
** Last update Sat Mar 19 16:03:09 2016 fabrice sepret
*/

#include <stdlib.h>
#include "tetris.h"

unsigned char	**change_kr(unsigned char *av, unsigned char **param)
{
  if (av == NULL || av[0] == '-')
    {
      my_putstr_er("./tetris : missing operand\n");
      my_putstr_er("try './tetris --help' for more information.\n");
      exit(-1);
    }
  param[2] = "Key Right : ";
  param[2] = my_strcat(param[2], av);
  return (param);
}

unsigned char	**m_change_kr(unsigned char **param, unsigned char *av)
{
  int		i;
  int		j;
  unsigned char	*str;

  i = 0;
  j = 0;
  if ((str = malloc(sizeof(char *) * my_strlen(av))) == NULL)
    exit (-1);
  while (av[i] != '=')
    i += 1;
  i += 1;
  while (av[i] != 0)
    {
      if (av[i] == ' ')
	str = my_strcat(str, "(space)");
      else
	str[j] = av[i];
      j += 1;
      i += 1;
    }
  param[2] = "Key Right : ";
  param[2] = my_strcat(param[2], str);
  free(str);
  return (param);
}
