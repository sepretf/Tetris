/*
** raw.c for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Wed Mar  2 13:21:23 2016 fabrice sepret
** Last update Fri Mar 18 14:54:23 2016 fabrice sepret
*/

#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>

void	brut(int activer)
{
  static struct termios	raw;
  static struct termios	normal;
  static int		brut_actif;

  if (brut_actif == activer);
  if (activer)
    {
      ioctl(STDIN_FILENO, TCGETS, &normal);
      ioctl(STDIN_FILENO, TCGETS, &raw);
      raw.c_lflag &= ~(ECHO| ECHONL | ICANON | ISIG | IEXTEN);
      ioctl(STDIN_FILENO, TCSETS, &raw);
    }
  else
    ioctl(STDIN_FILENO, TCSETS, &normal);
  brut_actif = activer;
}
