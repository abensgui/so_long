/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:11:17 by abensgui          #+#    #+#             */
/*   Updated: 2022/02/19 18:24:37 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_x(char **s)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i][j])
			j++;
		i++;
	}
	return (i);
}

void	check_line(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_strlen(str[0]) != ft_strlen(str[i]))
		{
			ft_printstr("error line");
			exit(1);
		}
		i++;
	}
	if (ft_strlen(str[0]) == ft_strlen_x(str))
	{
		ft_printstr("error map in rect");
		exit(1);
	}
}

void	ft_check_conut_map(char *str, t_vars *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			data->count_wall++;
		if (str[i] == 'P')
			data->count_player++;
		if (str[i] == 'C')
			data->count_coin++;
		if (str[i] == 'E')
			data->count_exit++;
		if (str[i] == '0')
			data->count_space++;
		i++;
	}
	data->count_map = i;
	if (data->count_player != 1 || data->count_coin < 1
		|| data->count_exit < 1 || data->count_space < 1)
	{
		ft_printstr("error element");
		exit(1);
	}
}

void	check_element(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'C' &&
			str[i][j] != 'E' && str[i][j] != 'P' && str[i][j] != 'I')
			{
				ft_printstr("error element");
				exit(1);
			}
			j++;
		}
		if (str[i][0] != '1' || str[i][ft_strlen(str[0]) - 1] != '1')
		{
			ft_printstr("error wall");
			exit(1);
		}
		i++;
	}
}

void	check_map(char **str)
{
	int	i;

	i = 0;
	while (str[0][i])
	{
		if (str[0][i] != '1' || str[ft_strlen_x(str) - 1][i] != '1')
		{
			ft_printstr("error wall");
			exit(1);
		}
		i++;
	}
	check_element(str);
	check_line(str);
}
