/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:26:25 by lfouquet          #+#    #+#             */
/*   Updated: 2016/03/09 18:22:44 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve_square(t_map *map, t_fillit *fillit, int len)
{
	*map = init_map(len);
	if (solve2(map, fillit->pieces))
		return (1);
	else
	{
		free_map(*map);
		return (0);
	}
}

int		solve2(t_map *map, t_piece *piece)
{
	t_pos		pos;

	pos = init_pos(1,1);
	if (!piece)
		return (1);
	while (set_pos_free(*map, &pos, piece->height))
	{
		if (can_put_piece(*map, piece, pos))
		{
			do_put_piece(map, piece, pos);
			if (solve2(map, piece->next))
				return (1);
			else
				delete_piece_map(map, piece->c, pos);
		}
		set_next_pos(map->len, &pos);
	}
	return (0);
}

void	set_next_pos(int len, t_pos *pos)
{
	if (pos->x == len && pos->y == len)
		return;
	if (pos->x == len)
	{
		pos->x = 1;
		if (pos->y == len)
			return;
		pos->y++;
	}
	else
		pos->x++;
	return;
}
