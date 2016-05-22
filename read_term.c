/*
** read_term.c for  in /home/sepret_f/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Fri Mar 18 17:58:20 2016 fabrice sepret
** Last update Sat Mar 19 16:25:16 2016 fabrice sepret
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "tetris.h"

void	my_quit()
{
  endwin();
  my_putstr("Exit :\nYour score : ");
  my_putnbr(score);
  my_putchar('\n');
  exit(0);
}

unsigned char	*get_param(unsigned char *str)
{
  int		i;
  int		j;
  unsigned char	*cmd;

  i = 0;
  j = 0;
  if ((cmd = malloc(100 * sizeof(char *))) == NULL)
    exit(-1);
  while (str[i] != 0 && str[i] != ':')
    i += 1;
  i += 2;
  while (str[i] != 0)
    {
      cmd[j] = str[i];
      j += 1;
      i += 1;
    }
  cmd[j] = 0;
  return (cmd);
  free(cmd);
}

int	**get_cmd(unsigned char **param, t_var var, int **tab)
{
  t_char str;
  int	i;

  i = 1;
  if ((str.right = malloc(100 * sizeof(char *))) == NULL
      || (str.left = malloc(100 * sizeof(char *))) == NULL
      || (str.drop = malloc(100 * sizeof(char *))) == NULL
      || (str.buf = malloc(1000)) == NULL
      || (str.quit = malloc(100 * sizeof(char *))) == NULL)
    exit(-1);
  str.right = get_param(param[2]);
  str.left = get_param(param[1]);
  str.drop = get_param(param[4]);
  str.quit = get_param(param[5]);
  ioctl(0, FIONBIO, &i);
  read(0, str.buf, 1000);
  if ((my_strcmp(str.buf, str.right)) == 0)
    tab = con_right(tab, var, var.y, var.x);
  if ((my_strcmp(str.buf, str.left)) == 0)
    tab = con_left(tab, var, var.y, var.x);
  if ((my_strcmp(str.buf, str.quit)) == 0)
    my_quit();
  return (tab);
}
