/*
** my_strcmp_n.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Feb 25 15:34:19 2016 fabrice sepret
** Last update Sat Mar 19 16:14:59 2016 fabrice sepret
*/

int	my_strcmp_n(unsigned char *str1, unsigned char *str2, int n)
{
  int	i;

  i = 0;
  while (i < n && (str1[i] != 0 || str2[i] != 0))
    {
      if (str1[i] != str2[i])
	return (1);
      i += 1;
    }
  if (i == n)
    return (0);
  return (1);
}
