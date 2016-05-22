/*
** tetris.h for  in /home/sepret_f/sem2/psu/PSU_2015_tetris
**
** Made by fabrice sepret
** Login   <sepret_f@epitech.net>
**
** Started on  Thu Feb 25 10:15:34 2016 fabrice sepret
** Last update Sat Mar 19 16:45:34 2016 fabrice sepret
*/

#ifndef		TETRIS_H_
# define	TETRIS_H_

unsigned char	**param;
int		score;

typedef struct	s_var
{
  int		j;
  int		i;
  int		m;
  int		l;
  int		z;
  int		x;
  int		y;
  int		idx;
}		t_var;

typedef struct	s_char
{
  unsigned char	*right;
  unsigned char	*left;
  unsigned char	*drop;
  unsigned char	*buf;
  unsigned char	*quit;
  unsigned char	*pause;
}		t_char;

unsigned char	**change_lvl(unsigned char *av, unsigned char **param);
unsigned char	*my_strcat(unsigned char *param, unsigned char *av);
unsigned char	**parametre(unsigned char **param);
unsigned char	**map_size(unsigned char **param, unsigned char *str);
unsigned char	**change_kl(unsigned char *av, unsigned char **param);
unsigned char	**change_kr(unsigned char *av, unsigned char **param);
unsigned char	**change_kt(unsigned char *av, unsigned char **param);
unsigned char	**change_kd(unsigned char *av, unsigned char **param);
unsigned char	**change_kq(unsigned char *av, unsigned char **param);
unsigned char	**change_kp(unsigned char *av, unsigned char **param);
unsigned char	**disp_next(unsigned char *av, unsigned char **param);
unsigned char	**m_change_lvl(unsigned char **param, unsigned char *av);
unsigned char	**m_change_kl(unsigned char **param, unsigned char *av);
unsigned char	**m_change_kr(unsigned char **param, unsigned char *av);
unsigned char	**m_change_kt(unsigned char **param, unsigned char *av);
unsigned char	**m_change_kp(unsigned char **param, unsigned char *av);
unsigned char	**m_change_kd(unsigned char **param, unsigned char *av);
unsigned char	**m_change_kq(unsigned char **param, unsigned char *av);
unsigned char	*my_cat(unsigned char *av1, int j);
unsigned char	*my_tet(unsigned char *av, unsigned char *str);
unsigned char	*tetrimi(unsigned char *str);
int	**con_down(int **tab, t_var var, int y, int x);
int	**change_int(int **tab, int y, int x);
int	**now_down(int **tab, int y, int x);
t_var	init_disp(t_var var);
int	**con_right(int **tab, t_var var, int y, int x);
int	**con_left(int **tab, t_var var, int y, int x);
unsigned char	*get_right(unsigned char *str);
unsigned char	*get_left(unsigned char *str);
unsigned char	*get_drop(unsigned char *str);
int	**get_cmd(unsigned char **param, t_var var, int **tab);

#endif /* !TETRIS_H_ */
