/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:17:04 by lfouquet          #+#    #+#             */
/*   Updated: 2016/03/07 15:45:33 by lfouquet         ###   ########.fr       */
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
	ft_putchar('\n');
}

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.len)
		free(map.map[i++]);
	free(map.map);
}

int		set_pos_free(t_map map, t_pos *pos)
{
	int	i;
	int	j;

	if (pos->y >= map.len && pos->x >= map.len)
		return (0);
	i = pos->y - 1;
	j = pos->x - 1;
	while (i < map.len)
	{
		while(j < map.len)
		{
			if (map.map[i][j] == '.')
			{
				pos->x = j + 1;
				pos->y = i + 1;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}