/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:17:04 by lfouquet          #+#    #+#             */
/*   Updated: 2016/02/25 18:48:29 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	init_map(int len)
{
	t_map	map;
	int		i;

	i = 0;
	map.len = len;
	map.map = NULL;
	map.map = (char**)malloc(sizeof(char*) * len);
	while (i < len)
	{
		map.map[i] = (char*)ft_memalloc(sizeof(char) * (len + 1));
		map.map[i] = init_value_line_map(map.map[i], len);
		i++;
	}
	return (map);
}

char	*init_value_line_map(char *line, int len)
{
	int	i;

	i = 0;
	while (i < len)
		line[i++] = '.';
	line[i] = '\0';
	return (line);
}

void	print_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map.len)
	{
		j = 0;
		while (map.map[i][j])
		{
			ft_putchar(map.map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.len)
		free(map.map[i++]);
	free(map.map);
}

t_pos	get_first_pos_map(t_map map)
{
	t_pos	pos;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map.len)
	{
		j = 0;
		while(j < map.len)
		{
			if (map.map[i][j] == '.')
			{
				pos.x = j + 1;
				pos.y = i + 1;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}