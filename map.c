/*
** map.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Wed Feb 24 14:21:28 2016 fabrice sepret
** Last update Sat Mar 19 16:16:01 2016 fabrice sepret
*/

#include <ncurses.h>
#include <stdlib.h>

int	my_map2(int i, int col, int line, unsigned char **param)
{
  if (line >= col && col % 2 != 0 || line < col && col % 2 != 0)
    {
      while (i != (line + 2))
	{
	  mvprintw(i, (COLS / 2 - (col / 2)), "|");
	  mvprintw(i, (COLS / 2 + (col / 2) + 2), "|");
	  i += 1;
	}
      next((COLS / 2 + (col / 2) + 2), param);
    }
  else
    {
      while (i != (line + 2))
	{
	  mvprintw(i, (COLS / 2 - (col / 2)), "|");
	  mvprintw(i, (COLS / 2 + (col / 2) + 1), "|");
	  i += 1;
	}
      next((COLS / 2 + (col / 2) + 1), param);
    }
}

int	my_map1(int i, int col, int line, unsigned char **param)
{
  if (col % 2 == 0)
    {
      while (i != (line + 2))
	{
	  mvprintw(i, (COLS / 2 - (col / 2)), "|");
	  mvprintw(i, (COLS / 2 + (col / 2) + 1), "|");
	  i += 1;
	}
      next((COLS / 2 + (col / 2) + 1), param);
    }
  else
    {
      while (i != (line + 2))
	{
	  mvprintw(i, (COLS / 2 - (col / 2)), "|");
	  mvprintw(i, (COLS / 2 + (col / 2) + 2), "|");
	  i += 1;
	}
      next((COLS / 2 + (col / 2) + 1), param);
    }
}
