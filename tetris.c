/*
** tetris.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Mon Feb 22 10:17:43 2016 fabrice sepret
** Last update Sat Mar 19 16:13:13 2016 fabrice sepret
*/

#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

void	help(char *av)
{
  my_putstr("Usage: ");
  my_putstr(av);
  my_putstr(" [options]\nOptions:\n--help");
  my_putstr("                 Display this help\n");
  my_putstr("-l --level={num}       Start");
  my_putstr(" Tetris at level num\n-kl --key-left={K} ");
  my_putstr("    Move tetrimino on LEFT with key K\n-kr ");
  my_putstr("--key-right={K}    Move tetrimino");
  my_putstr(" on RIGHT with key K\n-kt --key-turn={K} ");
  my_putstr("    Turn tetrimino with key K\n-kd ");
  my_putstr("--key-drop={K}     Set default DROP on ");
  my_putstr("key K\n-kq --key-quit={K}     Quit program ");
  my_putstr("when press key K\n-kp --key-pause={K} ");
  my_putstr("   Pause and restart game when press key ");
  my_putstr("K\n--map-size={row,col}   Set game size at ");
  my_putstr("row, col\n-w --without-next ");
  my_putstr("     Hide next tetrimino\n-d --debug             Debug mode\n");
  exit(0);
}

unsigned char	**more_options(unsigned char *av, unsigned char *av1,
			       unsigned char **param, unsigned char *av0)
{
  if ((my_strcmp_n("--map-size=", av, 11)) == 0)
    param = map_size(param, av);
  else if ((my_strcmp_n("--level=", av, 8)) == 0)
    param = m_change_lvl(param, av);
  else if ((my_strcmp_n("--key-left=", av, 11)) == 0)
    param = m_change_kl(param, av);
  else if ((my_strcmp_n("--key-right=", av, 12)) == 0)
    param = m_change_kr(param, av);
  else if ((my_strcmp_n("--key-turn=", av, 11)) == 0)
    param = m_change_kt(param, av);
  else if ((my_strcmp_n("--key-drop=", av, 11)) == 0)
    param = m_change_kd(param, av);
  else if ((my_strcmp_n("--key-quit=", av, 11)) == 0)
    param = m_change_kq(param, av);
  else if ((my_strcmp_n("--key-pause=", av, 12)) == 0)
    param = m_change_kp(param, av);
  else if ((my_strcmp_n("--without-next", av, 14)) == 0)
    param = disp_next(av1, param);
  return (param);
}

unsigned char	**help_options(unsigned char *av, unsigned char *av1
			       , unsigned char **param, unsigned char *av0)
{
  if ((my_strcmp("-l", av)) == 0)
    param = change_lvl(av1, param);
  else if ((my_strcmp("-kl", av)) == 0)
    param = change_kl(av1, param);
  else if ((my_strcmp("-kr", av)) == 0)
    param = change_kr(av1, param);
  else if ((my_strcmp("-kt", av)) == 0)
    param = change_kt(av1, param);
  else if ((my_strcmp("-kd", av)) == 0)
    param = change_kd(av1, param);
  else if ((my_strcmp("-kq", av)) == 0)
    param = change_kq(av1, param);
  else if ((my_strcmp("-kp", av)) == 0)
    param = change_kp(av1, param);
  else if ((my_strcmp("-w", av)) == 0)
    param = disp_next(av1, param);
  else if ((my_strcmp("--help", av)) == 0)
    help(av0);
  param = more_options(av, av1, param, av0);
  return (param);
}

int	main(int ac, unsigned char **av)
{
  int	i;
  int	j;

  j = 0;
  if ((param = malloc(11 * sizeof(*param))) == NULL)
    exit(-1);
  param = parametre(param);
  if (ac > 1)
    {
      i = 1;
      while  (av[i] != 0)
	{
	  if ((my_strcmp("-d", av[i])) == 0
	      || (my_strcmp_n("--debug", av[i], 7)) == 0)
	    j = 5;
	  else
	    param = help_options(av[i], av[i + 1], param, av[0]);
	  i++;
	}
      if (j == 5)
	disp_d(param);
    }
  get_line(param);
}
