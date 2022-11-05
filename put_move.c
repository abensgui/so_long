/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:47:26 by abensgui          #+#    #+#             */
/*   Updated: 2022/02/19 16:57:56 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_move(t_vars *data)
{
	char	*t;

	t = ft_itoa(data->move);
	mlx_put_image_to_window(data->mlx, data->win, data->img_wall, 64, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img_wall, 96, 0);
	mlx_string_put(data->mlx, data->win,
		64, 0, 0XFF0000, t);
	ft_printstr("move :");
	ft_printstr(t);
	free(t);
}
