/*
** move.c for  in /home/sepret_f/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Fri Mar 18 17:20:33 2016 fabrice sepret
** Last update Fri Mar 18 21:54:47 2016 fabrice sepret
*/

#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

int	check_right(int **tab, t_var var, int y, int x)
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
	  if (tab[i][j] == 3 && (tab[i][j + 1] == 0 || tab[i][j + 1] == 3))
	    idx = 10;
	  else if (tab[i][j] == 3 && (tab[i][j + 1] != 0 || tab[i][j + 1] != 3))
	    return (1);
	  j += 1;
	}
      j = 0;
      i += 1;
    }
  return (idx);
}

int	check_left(int **tab, t_var var, int y, int x)
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
	  if (tab[i][j] == 3 && (tab[i][j - 1] == 0 || tab[i][j - 1] == 3))
	    idx = 10;
	  else if (tab[i][j] == 3 && (tab[i][j - 1] != 0 || tab[i][j - 1] != 3))
	    return (1);
	  j += 1;
	}
      j = 0;
      i += 1;
    }
  return (idx);
}

int	**con_right(int **tab, t_var var, int y, int x)
{
  int	i;

  if ((i = check_right(tab, var, y, x)) == 10)
    {
      while (var.j != 0)
	{
	  while (var.i != 0)
	    {
	      if (tab[var.j][var.i] == 3)
		{
		  tab[var.j][var.i + 1] = 3;
		  tab[var.j][var.i] = 0;
		}
	      var.i -= 1;
	    }
	  var.i = x;
	  var.j -= 1;
	}
      disp_win(tab, y, x);
    }
  return (tab);
}

int	**con_left(int **tab, t_var var, int y, int x)
{
  int	i;

  var.i = 0;
  var.j = 0;
  if ((i = check_left(tab, var, y, x)) == 10)
    {
      while (var.j != y)
	{
	  while (var.i != x)
	    {
	      if (tab[var.j][var.i] == 3)
		{
		  tab[var.j][var.i - 1] = 3;
		  tab[var.j][var.i] = 0;
		}
	      var.i += 1;
	    }
	  var.i = 0;
	  var.j += 1;
	}
      disp_win(tab, y, x);
    }
  return (tab);
}
