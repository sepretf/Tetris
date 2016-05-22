/*
** param.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Wed Feb 24 10:09:57 2016 fabrice sepret
** Last update Sat Mar 19 16:19:03 2016 fabrice sepret
*/

#include <stdlib.h>
#include "tetris.h"

int		get_col(char *str, int i, char *line, unsigned char **param)
{
  int		e;
  unsigned char	*col;

  if ((col = malloc(sizeof(char *) * my_strlen(str))) == NULL)
    exit(-1);
  e = 0;
  e = 0;
  while (str[i] != 0)
    {
      if (str[i] != ' ' && str[i] >= '0' && str[i] <= '9')
	{
	  col[e] = str[i];
	  e += 1;
	}
      i += 1;
    }
  init_plat(my_atoi(col), my_atoi(line), param);
}

int		get_line(unsigned char **param)
{
  int		i;
  int		e;
  unsigned char	*line;

  if ((line = malloc(sizeof(char *) *my_strlen(param[9]))) == NULL)
    exit(-1);
  i = 0;
  e = 0;
  while (param[9][i - 1] != ' ' && param[9][i - 2] != ':')
    i += 1;
  while (param[9][i] != '*' && param[9][i] != ',' && param[9][i] != 0)
    {
      if (param[9][i] != ' ' && param[9][i] >= '0' && param[9][i] <= '9')
	{
	  line[e] = param[9][i];
	  e += 1;
	}
      i += 1;
    }
  i += 1;
  get_col(param[9], i, line, param);
}

unsigned char	**parametre(unsigned char **param)
{
  int	i;

  i = 0;
  param[0] = "*** DEBUG MODE ***";
  param[1] = "Key Left :  ^EOD";
  param[2] = "Key Right : ^EOC";
  param[3] = "Key Turn : ^[[A";
  param[4] = "Key Drop : ^[[B";
  param[5] = "Key Quit : q";
  param[6] = "Key Pause : (space)";
  param[7] = "Next : Yes";
  param[8] = "Level : 1";
  param[9] = "Size : 20*10";
  param[10] = 0;
  return (param);
}
