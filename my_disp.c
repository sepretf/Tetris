/*
** my_disp.c for  in /home/sepret_f/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Mon Mar 14 14:49:11 2016 fabrice sepret
** Last update Mon Mar 14 14:49:24 2016 fabrice sepret
*/

#include "tetris.h"

t_var	init_disp(t_var var)
{
  var.m = 1;
  var.l = 1;
  var.j = 0;
  var.z = 0;
  return (var);
}
