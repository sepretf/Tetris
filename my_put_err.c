/*
** my_put_err.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
** 
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
** 
** Started on  Thu Feb 25 10:14:15 2016 fabrice sepret
** Last update Thu Feb 25 10:24:23 2016 fabrice sepret
*/

int	my_putchar_e(unsigned char c)
{
  write(2, &c, 1);
}

int	my_putstr_er(unsigned char *st)
{
  int	i;

  i = 0;
  if (st ==  '\0')
    {
      write(2, &"(null)", 6);
      return (1);
    }
  while (st[i] != 0)
    {
      if (st[i] == '\\' && st[i + 1] == 'n')
	my_putchar_e('\n');
      else
	my_putchar_e(st[i]);
      i = i + 1;
    }
  return (0);
}
