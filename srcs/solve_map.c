/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:26:25 by lfouquet          #+#    #+#             */
/*   Updated: 2016/03/04 19:07:56 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve_square(t_map *map, t_fillit *fillit, int len)
{
	*map = init_map(len);

	if (solve2(map, fillit->pieces))
		return (1);
	else
	{
		printf("on free la map de taille ->%d\n", map->len);
		free_map(*map);
		return (0);
	}
}

int	solve2(t_map *map, t_piece *piece)
{
	t_pos		pos;
	t_piece		*tmp;

	pos = init_pos(1, 1);
	tmp = piece;
	if (!tmp)
		return (1);
	while (set_pos_free(*map, &pos))
	{
		if (!tmp)
			printf("alerte\n");
		//printf("Try Piece %c, en [%d]/[%d]\n", tmp->c, pos.y - 1, pos.x - 1);
		if (can_put_piece(*map, tmp, pos))
		{
			do_put_piece(&map, tmp, pos);
			print_map(*map);
			//printf("Piece %c, placé en [%d]/[%d]\n", tmp->c, pos.y - 1, pos.x - 1);
			//(*fillit)->pieces->put = 1;
			tmp = tmp->next;
			if (!tmp)
				return (1);
			if (solve2(map, tmp))
				return (1);

		}
		else
		{
			set_next_pos(map, &pos);
			//printf("nouvelle pos trouve ->[%d][%d]\n", pos.y - 1, pos.x - 1);
		}
	}
	printf("plus de PLACE dans la PLACE\n");
	if (!tmp)
		return (1);
	else
	{
		printf("piece perdu ->%c\n", piece->c);
		return (0);
	}
}

int		set_next_pos(t_map *map, t_pos *pos)
{
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
