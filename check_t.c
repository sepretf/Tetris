/*
** check_t.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Fri Mar  4 09:52:07 2016 fabrice sepret
** Last update Sat Mar 19 16:25:46 2016 fabrice sepret
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "tetris.h"

int	get_name(unsigned char *str)
{
  int	i;

  i = 0;
  while (str[i] != '.')
    {
      my_putchar(str[i]);
      i += 1;
    }
  my_putstr(" : ");

}

int	get_size(unsigned char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  my_putstr("Size ");
  while (str[i] != ' ' && str[i] != 0)
    {
      my_putchar(str[i]);
      i += 1;
    }
  my_putchar('*');
  i += 1;
  while (str[i] != ' ' && str[i] != 0)
    {
      my_putchar(str[i]);
      i += 1;
    }
  get_color((i + 1), str);
}

int	disp(unsigned char **tet)
{
  int	i;
  int	j;

  i = 0;
  while (tet[i] != 0)
    {
      my_putstr("Tetriminos : Name ");
      get_name(tet[i]);
      get_size(my_cat(my_strcat("tetriminos/", tet[i]), 1));
      my_putchar('\n');
      i += 1;
    }
}

unsigned char	*tetrimi(unsigned char *str)
{
  int		i;
  int		j;
  unsigned char	*file;

  i = 0;
  j = 0;
  if ((file = malloc(sizeof(char *) * my_strlen(str))) == NULL)
    exit(-1);
  while (str[i] != '.' && str[i++] != 0);
  if (str[i] == 0)
    return (NULL);
  while (str[i] != 0)
    file[j++] = str[i++];
  if (my_strcmp(file, ".tetrimino") == 0)
    return (str);
  return (NULL);
}

unsigned char	**check_t()
{
  struct dirent	*str;
  DIR		*rep;
  unsigned char	**tet;
  int		i;

  if ((tet = malloc(sizeof(char **) * (1000))) == NULL)
    exit(-1);
  i = 0;
  if ((rep = opendir("tetriminos")) == NULL)
    {
      my_putstr_er("Error: repository ''tetriminos'' not found\n");
      exit(-1);
    }
  while ((str = readdir(rep)) != NULL)
    if (tetrimi(str->d_name) != NULL)
      tet[i++] = tetrimi(str->d_name);
  i = 0;
  while (tet[i++] != 0);
  my_putstr("Tetriminos : ");
  my_putnbr(i - 1);
  my_putchar('\n');
  disp(tet);
}
