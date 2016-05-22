/*
** disp_game.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Mar 10 15:04:44 2016 fabrice sepret
** Last update Sat Mar 19 13:16:24 2016 fabrice sepret
*/

#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

int	disp_0(int **tab, int y, int x)
{
  int	posx;
  int	posy;
  int	i;
  int	j;

  j = 0;
  posx = (COLS / 2 - (x / 2)) + 1;
  posy = 1;
  i = 0;
  while (j <= y)
    {
      while (i != x)
	{
	  if (tab[j][i] == 3)
	    mvprintw(posy, (posx + i), "*");
	  if (tab[j][i] == 0)
	    mvprintw(posy, (posx + i), " ");
	  i += 1;
	}
      i = 0;
      j += 1;
      posy += 1;
    }
  refresh();
}

int	disp_1(int **tab, int y, int x)
{
  int	posx;
  int	posy;
  int	i;
  int	j;

  j = 0;
  posx = (COLS / 2 - (x / 2));
  posy = 1;
  i = 0;
  while (j <= y)
    {
      while (i != x)
	{
	  if (tab[j][i] == 3 || tab[j][i] == 6)
	    mvprintw(posy, (posx + i), "*");
	  if (tab[j][i] == 0)
	    mvprintw(posy, (posx + i), " ");
	  i += 1;
	}
      i = 0;
      j += 1;
      posy += 1;
    }
  refresh();
}

int	disp_win(int **tab, int y, int x)
{
  if (x % 2 == 0)
    disp_0(tab, y, x);
  else if (x % 2 != 0)
    disp_1(tab, y, x);
}

int	**now_down(int **tab, int y, int x)
{
  t_var	var;

  var.l = 0;
  var.j = y;
  var.i = x;
  var.y = y;
  var.x = x;
  disp_win(tab, y, x);
  tab = con_down(tab, var, y, x);
  usleep(500000 / (my_atoi(get_param(param[8]))));
  disp_win(tab, y, x);
  return (tab);
}

int	disp_g(char *tetri, int **tab, int y, int x)
{
  t_var	var;

  var = init_disp(var);
  while (var.j != y)
    {
      while (tetri[var.z] != 0)
	{
	  if (tetri[var.z] == '\n')
	    {
	      var.l = 1;
	      var.m += 1;
	    }
	  else if (tetri[var.z] == '*')
	    {
	      tab[var.m][((x / 2) + var.l)] = 3;
	      var.l += 1;
	    }
	  else
	    var.l += 1;
	  var.z += 1;
	}
      var.j += 1;
      tab = now_down(tab, y, x);
    }
}
