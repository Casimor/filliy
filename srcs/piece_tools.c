/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:05:02 by lfouquet          #+#    #+#             */
/*   Updated: 2016/02/25 18:45:07 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_put_piece(t_map map, t_piece *piece, t_pos pos)
{
	if (map.map[pos.x][pos.y] != '.')
		return (0);
	if (!check_pos_part_piece(pos, piece->p2, piece->p1, map))
		return (0);
	if (!check_pos_part_piece(pos, piece->p3, piece->p1, map))
		return (0);
	if (!check_pos_part_piece(pos, piece->p4, piece->p1, map))
		return (0);
	return (1);
}

int	check_pos_part_piece(t_pos pos, t_pos part, t_pos p1, t_map map)
{
	t_pos	tmp;

	tmp.x = part.x - p1.x;
	tmp.y = part.y - p1.y;
	if (pos.x + tmp.x < 0 || pos.x + tmp.x > map.len)
		return (0);
	else if (pos.y + tmp.y < 0 || pos.y + tmp.y > map.len)
		return (0);
	else if (map.map[pos.x + tmp.x][pos.y + tmp.y] != '.')
		return (0);
	else
		return (1);
}

void	do_put_piece(t_map	**map, t_piece *piece, t_pos pos)
{
	(*map)->map[pos.x + piece->p1.x][pos.y + piece->p1.y] = piece->c;
	(*map)->map[pos.x + piece->p2.x][pos.y + piece->p2.y] = piece->c;
	(*map)->map[pos.x + piece->p3.x][pos.y + piece->p3.y] = piece->c;
	(*map)->map[pos.x + piece->p4.x][pos.y + piece->p4.y] = piece->c;
}

int		all_pieces_puted(t_piece *piece)
{
	while (piece)
	{
		if (piece->put == 0)
			return (0);
		piece = piece->next;
	}
	return (1);
}