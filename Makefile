CC = cc -g -Wall -Werror -Wextra

MLX = -lmlx -framework OpenGL -framework AppKit

SRCS =	so_long.c\
		ft_split.c\
		get_next_line_utils.c\
		get_next_line.c\
		read_map.c\
		check_map.c\
		ft_move.c\
		ft_itoa.c\
		ft_render_map.c\
		ft_animation.c\
		ft_strcmp.c\
		ft_anim_enemy.c\
		put_move.c\
		ft_printstr.c\

ARV = ar -rcs

NAME = so_long

REM = rm -f

all : $(NAME)
$(NAME) :
	@-$(CC) $(MLX) ${SRCS} -o so_long

clean :
	@-${REM} ${NAME}

fclean : clean
	@-${REM} ${NAME}

re : fclean all