/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:05:55 by abensgui          #+#    #+#             */
/*   Updated: 2022/02/19 18:24:06 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_printstr("error : line vide in map");
			exit(1);
		}
		i++;
	}
}

char	**read_map(int fd, t_vars *data)
{
	char	*t;
	char	*str;
	char	**p;

	str = ft_strdup("");
	t = get_next_line(fd);
	while (t)
	{
		str = ft_strjoin(str, t);
		free(t);
		t = get_next_line(fd);
	}
	ft_check_line(str);
	ft_check_conut_map(str, data);
	p = ft_split(str, '\n');
	free(str);
	return (p);
}
