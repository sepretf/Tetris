/*
** get_size.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Mar 10 11:27:07 2016 fabrice sepret
** Last update Sat Mar 19 16:04:08 2016 fabrice sepret
*/

#include <stdlib.h>
#include "tetris.h"

int	get_size_m(unsigned char **tetri,
		   unsigned char **param, unsigned char *str)
{
  int		i;
  int		j;
  unsigned char	*x;
  unsigned char	*y;

  if ((x = malloc(sizeof(char *) * my_strlen(str))) == NULL
      || (y = malloc(sizeof(char *) * my_strlen(str))) == NULL)
    exit(1);
  i = 0;
  while (str[i - 2] != ' ' && str[i - 1] !=  ':' && str[i] != 0)
    i += 1;
  i += 1;
  j = 0;
  while (str[i] != ',' && str[i] != '*' && str[i] != 0)
    x[j++] = str[i++];
  i += 1;
  j = 0;
  while (str[i] != '\n' && str[i] != 0)
    y[j++] = str[i++];
  if (x[0] == 0 || y[0] == 0 || my_atoi(x) < 5 || my_atoi(y) < 5)
    wrong_map();
  init_tab(tetri, param, my_atoi(x), my_atoi(y));
}
