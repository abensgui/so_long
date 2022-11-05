/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:52:01 by abensgui          #+#    #+#             */
/*   Updated: 2022/02/19 16:33:09 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_map2(t_vars *data, int i, int j)
{
	if (data->map[i][j] == 'C')
	{
		data->img_coin = mlx_xpm_file_to_image(data->mlx,
				data->coin, &data->img_width, &data->img_height);
		mlx_put_image_to_window(data->mlx,
			data->win, data->img_coin, j * 32, 32 * i);
	}
	if (data->map[i][j] == 'E')
	{
		data->img_exit = mlx_xpm_file_to_image(data->mlx,
				data->exit, &data->img_width, &data->img_height);
		mlx_put_image_to_window(data->mlx,
			data->win, data->img_exit, j * 32, 32 * i);
	}
	if (data->map[i][j] == 'I')
	{
		data->img_enemy = mlx_xpm_file_to_image(data->mlx,
				data->enemy, &data->img_width, &data->img_height);
		mlx_put_image_to_window(data->mlx,
			data->win, data->img_enemy, j * 32, 32 * i);
		data->count_enemy++;
	}
}

void	ft_render_map1(t_vars *data, int i, int j)
{
	if (data->map[i][j] == '1')
	{
		data->img_wall = mlx_xpm_file_to_image(data->mlx,
				data->wall, &data->img_width, &data->img_height);
		mlx_put_image_to_window(data->mlx,
			data->win, data->img_wall, j * 32, 32 * i);
	}
	if (data->map[i][j] == '0')
	{
		data->img_space = mlx_xpm_file_to_image(data->mlx,
				data->space, &data->img_width, &data->img_height);
		mlx_put_image_to_window(data->mlx,
			data->win, data->img_space, j * 32, 32 * i);
	}
	if (data->map[i][j] == 'P')
	{
		data->x = i;
		data->y = j ;
		data->img_player = mlx_xpm_file_to_image(data->mlx,
				data->player, &data->img_width, &data->img_height);
		mlx_put_image_to_window(data->mlx,
			data->win, data->img_player, j * 32, 32 * i);
	}
}

void	ft_render_map(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			ft_render_map1(data, i, j);
			ft_render_map2(data, i, j);
			j++;
		}
		i++;
	}
}
