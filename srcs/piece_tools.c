/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:05:02 by lfouquet          #+#    #+#             */
/*   Updated: 2016/03/09 18:15:43 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_put_piece(t_map map, t_piece *piece, t_pos pos)
{
	pos.x -= 1;
	pos.y -= 1;
	if (map.map[pos.y][pos.x] != '.')
		return (0);
	if (!check_pos_part_piece(pos, piece->p2, map))
		return (0);
	if (!check_pos_part_piece(pos, piece->p3, map))
		return (0);
	if (!check_pos_part_piece(pos, piece->p4, map))
		return (0);
	return (1);
}

int		check_pos_part_piece(t_pos pos, t_pos part, t_map map)
{
	if (pos.x + 1 + part.x < 0 || pos.x + 1 + part.x > map.len)
		return (0);
	if (pos.y + 1 + part.y < 0 || pos.y + 1 + part.y > map.len)
		return (0);
	if (map.map[pos.y + part.y][pos.x + part.x] != '.')
		return (0);
	return (1);
}

void	do_put_piece(t_map *map, t_piece *piece, t_pos pos)
{
	map->map[pos.y - 1][pos.x - 1] = piece->c;
	map->map[pos.y + piece->p2.y - 1][pos.x + piece->p2.x - 1] = piece->c;
	map->map[pos.y + piece->p3.y - 1][pos.x + piece->p3.x - 1] = piece->c;
	map->map[pos.y + piece->p4.y - 1][pos.x + piece->p4.x - 1] = piece->c;
}

t_pos	init_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}
