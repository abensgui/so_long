/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:02:23 by abensgui          #+#    #+#             */
/*   Updated: 2022/02/19 18:28:49 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	ft_exit(void)
{
	exit(1);
}

static	void	ft_decl(t_vars *data)
{
	data->space = "./space.xpm";
	data->wall = "./wall.xpm";
	data->player = "./player.xpm";
	data->coin = "./coin.xpm";
	data->exit = "./exit.xpm";
	data->enemy = "./enemy.xpm";
}

static	void	so_long(t_vars *data)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	while (data->map[h])
	{
		while (data->map[h][w])
			w++;
		h++;
	}
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, w * 32, h * 32, "so_long");
	ft_render_map(data);
	mlx_hook(data->win, 2, 1L << 0, ft_move, data);
	mlx_hook(data->win, 17, 1L << 0, ft_exit, data);
	mlx_string_put(data->mlx, data->win, 0, 0, 0XFF0000, "move :");
	mlx_string_put(data->mlx, data->win, 64, 0, 0XFF0000, "0");
	mlx_loop_hook(data->mlx, ft_animation, data);
	mlx_loop(data->mlx);
}

void	ft_erorr(int ac)
{
	if (ac != 2)
		ft_printstr("erorr argument");
}

int	main(int ac, char **av)
{
	t_vars	*data;
	int		fd;
	char	**t;
	int		i;

	if (ac == 2)
	{
		i = 0;
		data = malloc(sizeof(t_vars));
		ft_decl(data);
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			perror("erorr fille map :");
			exit(1);
		}
		t = ft_split(av[1], '.');
		while (t[i])
			i++;
		ft_strcmp(t[i - 1], "ber");
		data->map = read_map(fd, data);
		check_map(data->map);
		so_long(data);
	}
	ft_erorr(ac);
}
