/*
** my_atoi.c for  in /home/sepret_f/progelem/CPE_2015_BSQ
** 
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
** 
** Started on  Sun Dec 20 19:28:56 2015 fabrice sepret
** Last update Tue Feb  9 11:48:28 2016 fabrice sepret
*/

int	my_atoi(unsigned char *str)
{
  int	a;
  int	b;
  int	idx;

  a = 0;
  b = 0;
  idx = 0;
  if (str[0] == '-')
    {
      a = 1;
      idx = 1;
    }
  while (str[a] != 0)
    {
      if (str[a] >= '0' && str[a] <= '9')
	{
	  b = b * 10;
	  b = b + str[a] - '0';
	}
      a = a + 1;
    }
  if (idx == 1)
    b = -b;
  return (b);
}
