/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:26:25 by lfouquet          #+#    #+#             */
/*   Updated: 2016/03/07 19:34:19 by lfouquet         ###   ########.fr       */
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
	t_piece		*tmp;

	pos = init_pos(1, 1);
	tmp = piece;
	if (!tmp)
		return (1);
	while (set_pos_free(*map, &pos))
	{
		if (can_put_piece(*map, tmp, pos))
		{
			do_put_piece(&map, tmp, pos);
			if (solve2(map, tmp->next))
				return (1);
			else
				delete_piece_map(map, tmp->c);
		}
		set_next_pos(map, &pos);
	}
	return (0);
}

int		set_next_pos(t_map *map, t_pos *pos)
{
	if (pos->x == map->len && pos->y == map->len)
		return (0);
	if (pos->x == map->len)
	{
		pos->x = 1;
		if (pos->y == map->len)
			return (0);
		pos->y++;
	}
	else
		pos->x++;
	return (1);
}
