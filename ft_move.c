/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:46:01 by abensgui          #+#    #+#             */
/*   Updated: 2022/02/19 17:04:51 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_vars *data)
{
	if (data->map[data->x - 1][data->y] != 'E')
	{
		if (data->map[data->x - 1][data->y] == 'I')
			exit(1);
		if (data->map[data->x - 1][data->y] == 'C')
			data->count_coin--;
		data->map[data->x - 1][data->y] = 'P';
		data->map[data->x][data->y] = '0';
		mlx_put_image_to_window(data->mlx, data->win,
			data->img_space, (data->y) * 32, data->x * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->img_player,
			(data->y) * 32, (data->x -1) * 32);
		data->x--;
		data->move++;
	}
	if (data->map[data->x - 1][data->y] != 'E')
		put_move(data);
	if (data->map[data->x - 1][data->y] == 'E' && data->count_coin == 0)
	{
		ft_printstr("you win");
		exit(1);
	}
}

void	ft_down(t_vars *data)
{
	if (data->map[data->x + 1][data->y] != 'E')
	{
		if (data->map[data->x + 1][data->y] == 'I')
			exit(1);
		if (data->map[data->x + 1][data->y] == 'C')
			data->count_coin--;
		data->map[data->x + 1][data->y] = 'P';
		data->map[data->x][data->y] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->img_space,
			(data->y) * 32, data->x * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->img_player,
			(data->y) * 32, (data->x + 1) * 32);
		data->x++;
		data->move++;
	}
	if (data->map[data->x - 1][data->y] != 'E')
		put_move(data);
	if (data->map[data->x + 1][data->y] == 'E' && data->count_coin == 0)
	{
		ft_printstr("you win");
		exit(1);
	}
}

void	ft_right(t_vars *data)
{
	if (data->map[data->x][data->y + 1] != 'E')
	{
		if (data->map[data->x][data->y + 1] == 'I')
			exit(1);
		if (data->map[data->x][data->y + 1] == 'C')
			data->count_coin--;
		data->map[data->x][data->y + 1] = 'P';
		data->map[data->x][data->y] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->img_space,
			(data->y) * 32, data->x * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->img_player,
			(data->y + 1) * 32, (data->x) * 32);
		data->y++;
		data->move++;
	}
	if (data->map[data->x - 1][data->y] != 'E')
		put_move(data);
	if (data->map[data->x][data->y + 1] == 'E' && data->count_coin == 0)
	{
		ft_printstr("you win");
		exit(1);
	}
}

void	ft_left(t_vars *data)
{
	if (data->map[data->x][data->y - 1] != 'E')
	{
		if (data->map[data->x][data->y - 1] == 'I')
			exit(1);
		if (data->map[data->x][data->y - 1] == 'C')
			data->count_coin--;
		data->map[data->x][data->y - 1] = 'P';
		data->map[data->x][data->y] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->img_space,
			(data->y) * 32, data->x * 32);
		mlx_put_image_to_window(data->mlx, data->win, data->img_player,
			(data->y - 1) * 32, (data->x) * 32);
		data->y--;
		data->move++;
	}
	if (data->map[data->x - 1][data->y] != 'E')
		put_move(data);
	if (data->map[data->x][data->y - 1] == 'E' && data->count_coin == 0)
	{
		ft_printstr("you win");
		exit(1);
	}
}

int	ft_move(int keycode, t_vars *data)
{
	if (keycode == 13 && data->map[data->x - 1][data->y] != '1' )
	{
		ft_up(data);
	}
	if (keycode == 1 && data->map[data->x + 1][data->y] != '1' )
	{
		ft_down(data);
	}
	if (keycode == 0 && data->map[data->x][data->y - 1] != '1' )
	{
		ft_left(data);
	}	
	if (keycode == 2 && data->map[data->x][data->y + 1] != '1')
	{
		ft_right(data);
	}
	if (keycode == 53)
	{
		exit(1);
	}
	return (0);
}
