/*
** get_color.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Fri Mar  4 15:33:57 2016 fabrice sepret
** Last update Sat Mar 19 16:17:35 2016 fabrice sepret
*/

int	get_color(int i, unsigned char *str)
{
  my_putstr(" : Color ");
  while (str[i] != ' ' && str[i] != '\n' && str[i] != 0)
    {
      my_putchar(str[i]);
      i += 1;
    }
  my_putstr(" :\n");
  i += 1;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i += 1;
    }
}
