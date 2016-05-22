##
## Makefile for  in /home/sepret_f/sem2/cpe/CPE_2015_Allum1
##
## Made by fabrice sepret
## Login   <sepret_f@epitech.net>
##
## Started on  Wed Feb 10 15:28:00 2016 fabrice sepret
## Last update Sat Mar 19 16:21:30 2016 fabrice sepret
##

SRC =	my_put.c \
	my_strcmp.c \
	tetris.c \
	error.c \
	display.c \
	param.c \
	my_atoi.c \
	map.c \
	change_lvl.c \
	my_strcat.c \
	my_put_err.c \
	change_map.c \
	my_strcmp_n.c \
	change_kl.c \
	change_kr.c \
	change_kt.c \
	change_kd.c \
	change_kq.c \
	change_kp.c \
	next.c \
	debug.c \
	raw.c \
	my_exit.c \
	check_t.c \
	my_cat.c \
	get_color.c \
	game.c \
	get_size.c \
	int_tab.c \
	disp_game.c \
	down.c \
	my_disp.c \
	move.c \
	read_term.c \

NAME =	tetris

OBJ =	$(SRC:.c=.o)

RM =	rm -rf

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(SRC) -lncurses

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
