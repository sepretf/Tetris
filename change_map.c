/*
** change_map.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Feb 25 14:51:03 2016 fabrice sepret
** Last update Sat Mar 19 16:17:20 2016 fabrice sepret
*/

#include <stdlib.h>
#include "tetris.h"

unsigned char	**map_size(unsigned char **param, unsigned char *str)
{
  int		i;
  int		j;
  unsigned char	*av;

  if ((av = malloc(sizeof(char *) * my_strlen(str))) == NULL)
    exit(-1);
  i = 0;
  j = 0;
  while (str[i - 1] != '=' && str[i - 2] != 'e')
    i += 1;
  while (str[i] != 0)
    {
      av[j] = str[i];
      j += 1;
      i += 1;
    }
  param[9] = "Size : ";
  param[9] = my_strcat(param[9], av);
  return (param);
}
