/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:40:14 by abensgui          #+#    #+#             */
/*   Updated: 2022/02/19 12:40:15 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_anim_enemy_up(t_vars *data, int i, int j)
{
	data->map[i][j] = '0';
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_space, j * 32, 32 * i);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_enemy, (j + 1) * 32, 32 * i);
	data->map[i][j + 1] = 'I';
}

void	ft_enemy_up(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	data->prev = -1;
	while (data->map[i])
	{	
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'I' && data->prev != j
			&& (data->map[i][j + 1] == '0' || data->map[i][j + 1] == 'P'))
			{
				if (data->map[i][j + 1] == 'P')
					exit(1);
				ft_anim_enemy_up(data, i, j);
				data->prev = j + 1;
			}
			j++;
		}
		i++;
	}
}

void	ft_anim_enemy_down(t_vars *data, int i, int j)
{
	data->map[i][j] = '0';
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_space, j * 32, 32 * i);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_enemy, (j - 1) * 32, 32 * i);
	data->map[i][j - 1] = 'I';
}

void	ft_enemy_down(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	data->prev = -1;
	while (data->map[i])
	{	
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'I' && data->prev != j
				&& (data->map[i][j - 1] == '0' || data->map[i][j - 1] == 'P'))
			{
				if (data->map[i][j - 1] == 'P')
					exit(1);
				ft_anim_enemy_down(data, i, j);
				data->prev = j - 1;
			}
			j++;
		}
		i++;
	}
}

void	ft_anim_enemy(t_vars *data)
{
	if (data->f == 4500)
	{
		ft_enemy_up(data);
	}
	if (data->f == 9000)
	{
		ft_enemy_down(data);
		data->f = 0;
	}
}
