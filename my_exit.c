/*
** my_exit.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Mar  3 09:49:46 2016 fabrice sepret
** Last update Thu Mar  3 09:52:22 2016 fabrice sepret
*/

#include <stdlib.h>
#include "tetris.h"

int	my_exit()
{
  my_putstr_er("./tetris : Bad argument(s)\n");
  my_putstr_er("try './tetris --help' for more information.\n");
  exit(-1);
}
