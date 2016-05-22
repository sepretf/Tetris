/*
** error.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Mon Feb 22 16:24:35 2016 fabrice sepret
** Last update Fri Mar 18 08:39:03 2016 fabrice sepret
*/

#include <stdlib.h>
#include <ncurses.h>

int	check_wind(int col, int line)
{
  if (COLS < (col + 60) || LINES < (line + 10))
    {
      endwin();
      write(2, "Windows too small\n", 18);
      exit(0);
    }
}

int	wrong_map()
{
  endwin();
  write(2, "Wrong map size (min 5*5)\n", 25);
  exit(0);
}
