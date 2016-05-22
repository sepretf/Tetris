/*
** int_tab.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Wed Mar  9 16:43:04 2016 fabrice sepret
** Last update Sat Mar 19 16:19:44 2016 fabrice sepret
*/

#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

int	disp_int(int **tab, int y, int x)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i != (y + 2))
    {
      while (j != (x + 1))
	{
	  my_putnbr(tab[i][j]);
	  j += 1;
	}
      my_putchar('\n');
      j = 0;
      i += 1;
    }
}

int	check_tab(int **tab, int x)
{
  int	i;

  i = 0;
  while (i != x)
    {
      if (tab[1][i] == 3 || tab[1][i] == 6)
	return (5);
      i += 1;
    }
  return (1);
}

int	now_tetri(unsigned char **tetri, int **tab, int y, int x)
{
  int	idx;
  int	i;
  int	j;

  j = 0;
  idx = 0;
  while (tetri[idx] != 0)
    idx += 1;
  while ((i = check_tab(tab, x)) != 5)
    {
      if (j > (idx - 1))
	j = 0;
      disp_g(tetri[j], tab, y, x);
      j += 1;
    }
  my_quit();
}

int	fill_tab(unsigned char **tetri, int **tab, int y, int x)
{
  int	i;
  int	j;
  int	c;

  c = y + 1;
  i = 1;
  tab[0][0] = -1;
  while (i <= x)
    {
      tab[0][i] = -3;
      tab[c][i] = -5;
      i +=1;
    }
  tab[0][i] = -1;
  i = 1;
  x = x + 1;
  while (i <= (y + 1))
    {
      tab[i][0] = -1;
      tab[i][x] = -1;
      i += 1;
    }
  now_tetri(tetri, tab, y, x);
}

int	init_tab(unsigned char **tetri, unsigned char **param, int y, int x)
{
  int	**tab;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(int *) * (y * 2))) == NULL)
    exit(-1);
  while (i != ((x + 1) * 2))
    {
      if ((tab[i] = malloc(sizeof(int *) * (x * 2))) == NULL)
	exit(-1);
      i += 1;
    }
  fill_tab(tetri, tab, y, x);
}
