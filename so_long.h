/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:56:26 by abensgui          #+#    #+#             */
/*   Updated: 2022/02/19 17:05:05 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
//////////////////////////////
# include<stdlib.h>
# include<fcntl.h>
# include<mlx.h>
# include<unistd.h>
# include<stdio.h>

typedef struct s_vars{
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_wall;
	void	*img_space;
	void	*img_coin;
	void	*img_exit;
	void	*img_enemy;
	char	**map;
	int		count_coin;
	int		count_wall;
	int		count_exit;
	int		count_space;
	int		count_player;
	int		count_enemy;
	int		count_map;
	int		move;
	int		f;
	int		x;
	int		y;
	char	*coin;
	char	*space;
	char	*wall;
	char	*player;
	char	*exit;
	char	*enemy;
	int		img_width;
	int		img_height;
	int		prev;
}				t_vars;
///////////////////////////////////
char	**read_map(int fd, t_vars *data);
char	**ft_split(const char *s, char c);
int		ft_move(int keycode, t_vars *data);
/////////////////////////////////////////////////
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *sr);
int		ft_strlen(const char *s);
void	check_map(char **str);
int		ft_strlen_x(char **s);
void	ft_check_conut_map(char *str, t_vars *data);
char	*ft_itoa(int n);
void	ft_render_map(t_vars *data);
int		ft_animation(t_vars *data);
void	ft_strcmp(char *s1, char *s2);
void	ft_anim_enemy(t_vars *data);
void	put_move(t_vars *data);
int		ft_printstr(char *str);
#endif
