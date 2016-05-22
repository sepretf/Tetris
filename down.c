/*
** down.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Fri Mar 11 11:11:44 2016 fabrice sepret
** Last update Sat Mar 19 13:04:11 2016 fabrice sepret
*/

#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

int	**change_int(int **tab, int y, int x)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j != (y + 2))
    {
      while (i != (x + 2))
	{
	  if (tab[j][i] == 3)
	    {
	      tab[j][i] = 6;
	      score += 1;
	    }
	  i += 1;
	}
      i = 0;
      j += 1;
    }
  mvprintw(14, 23, "%d", score);
  refresh();
  return (tab);
}

int	check_down(int **tab, t_var var, int y, int x)
{
  int	i;
  int	j;
  int	idx;

  idx = 1;
  i = 0;
  j = 0;
  while (i != (y + 2))
    {
      while (j != (x + 1))
	{
	  if (tab[i][j] == 3 && (tab[i + 1][j] == 0 || tab[i + 1][j] == 3))
	    idx = 10;
	  else if (tab[i][j] == 3 && (tab[i + 1][j] != 0 || tab[i + 1][j] != 3))
	    return (1);
	  j += 1;
	}
      j = 0;
      i += 1;
    }
  return (idx);
}

int	**con_down(int **tab, t_var var, int y, int x)
{
  int	i;

  if ((i = check_down(tab, var, y, x)) == 10)
    {
      while (var.j != 0)
	{
	  while (var.i != 0)
	    {
	      tab = get_cmd(param, var, tab);
	      if (tab[var.j][var.i] == 3)
		{
		  tab[var.j + 1][var.i] = 3;
		  tab[var.j][var.i] = 0;
		}
	      var.i -= 1;
	    }
	  var.i = x;
	  var.j -= 1;
	}
      disp_win(tab, y, x);
    }
  else
    tab = change_int(tab, y, x);
  return (tab);
}
