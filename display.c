/*
** display.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Tue Feb 23 16:00:13 2016 fabrice sepret
** Last update Sat Mar 19 16:18:39 2016 fabrice sepret
*/

#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

int	init_edge1(int col, int line, unsigned char **param)
{
  int	i;
  int	j;

  i = 2;
  j = 0;
  while (j != (col + 2))
    {
      mvprintw(1, ((COLS / 2 - (col / 2)) + j), "-");
      mvprintw((line + 2), ((COLS / 2 - (col / 2)) + j), "-");
      j += 1;
    }
  my_map1(i, col, line, param);
}

int	init_edge2(int col, int line, unsigned char **param)
{
  int	i;
  int	j;

  j = 0;
  i = 2;
  while (j != (col + 2))
    {
      mvprintw(1, ((COLS / 2 - (col / 2)) + j), "-");
      mvprintw((line + 2), ((COLS / 2 - (col / 2)) + j), "-");
      j += 1;
    }
  my_map2(i, col, line, param);
}

int	next(int i, unsigned char **param)
{
  if ((my_strcmp_n(param[7] , "Next : Yes", 10)) == 0)
    {
      mvprintw(1, (i + 4), "/NEXT---------\\");
      mvprintw(2, (i + 4), "|             |");
      mvprintw(3, (i + 4), "|             |");
      mvprintw(4, (i + 4), "|             |");
      mvprintw(5, (i + 4), "|             |");
      mvprintw(6, (i + 4), "|             |");
      mvprintw(7, (i + 4), "\\-------------/");
    }
}

int	score_tab()
{
  int	i;

  i = 12;
  mvprintw(11, 1, "/---------------------------\\");
  mvprintw(13, 2, "   High Score        100 ");
  mvprintw(14, 2, "   Score");
  mvprintw(14, 23, "%d", score);
  mvprintw(16, 2, "   Lines");
  mvprintw(17, 2, "   Level             %s", get_param(param[8]));
  mvprintw(20, 2, "   Timer:");
  mvprintw(22, 1, "\\---------------------------/");
  while (i != 22)
    {
      mvprintw(i, 1, "|");
      mvprintw(i, 29, "|");
      i += 1;
    }
  mvprintw(1, 1, "*** *** *** *** * ***");
  mvprintw(2, 1, " *  *    *  * *   *");
  mvprintw(3, 1, " *  **   *  **  * ***");
  mvprintw(4, 1, " *  *    *  * * *   *");
  mvprintw(5, 1, " *  ***  *  * * * ***");
}

int	init_plat(int col, int line, unsigned char **param)
{
  if ((newterm(NULL, stderr, stdin)) == NULL)
    return (0);
  curs_set(0);
  check_wind(col, line);
  if (COLS % 2 == 0)
    init_edge1(col, line, param);
  else if (COLS % 2 != 0)
    init_edge2(col, line, param);
  score_tab();
  get_tetrimi(param);
  endwin();
}
