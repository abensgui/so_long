/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:32:42 by abensgui          #+#    #+#             */
/*   Updated: 2022/02/19 13:45:10 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_anim1(t_vars *data)
{
	int	i;
	int	j;

	if (data->f == 3000)
	{	
		i = 0;
		while (data->map[i])
		{
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] == 'C')
				{
					data->coin = "./coin.xpm";
					data->img_coin = mlx_xpm_file_to_image(data->mlx,
							data->coin, &data->img_width, &data->img_height);
					mlx_put_image_to_window(data->mlx, data->win,
						data->img_coin, j * 32, 32 * i);
				}
				j++;
			}
			i++;
		}
	}
}

void	ft_anim2(t_vars *data)
{
	int	i;
	int	j;

	if (data->f == 6000)
	{
		i = 0;
		while (data->map[i])
		{
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] == 'C')
				{
					data->coin = "./coin1.xpm";
					data->img_coin = mlx_xpm_file_to_image(data->mlx,
							data->coin, &data->img_width, &data->img_height);
					mlx_put_image_to_window(data->mlx, data->win,
						data->img_coin, j * 32, 32 * i);
				}
				j++;
			}
			i++;
		}
	}	
}

void	ft_anim3(t_vars *data)
{
	int	i;
	int	j;

	if (data->f == 9000)
	{
		i = 0;
		while (data->map[i])
		{	
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] == 'C')
				{
					data->coin = "./coin2.xpm";
					data->img_coin = mlx_xpm_file_to_image(data->mlx,
							data->coin, &data->img_width, &data->img_height);
					mlx_put_image_to_window(data->mlx, data->win,
						data->img_coin, j * 32, 32 * i);
				}
				j++;
			}
			i++;
		}
	}
}

int	ft_animation(t_vars *data)
{
	data->f++;
	ft_anim1(data);
	ft_anim2(data);
	ft_anim3(data);
	ft_anim_enemy(data);
	return (0);
}
