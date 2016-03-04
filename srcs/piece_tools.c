/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:05:02 by lfouquet          #+#    #+#             */
/*   Updated: 2016/03/04 19:07:21 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_put_piece(t_map map, t_piece *piece, t_pos pos)
{
	pos.x -= 1;
	pos.y -= 1;
	if (map.map[pos.y][pos.x] != '.')
	{
		//printf("case prise ma guewule\n");
		return (0);
	}
	if (piece->width + pos.x > map.len || piece->height + pos.y  > map.len)
		return (0);
	//printf("p1 ok\n");
	if (!check_pos_part_piece(pos, piece->p2, piece->p1, map))
		return (0);
	//printf("p2 ok\n");
	if (!check_pos_part_piece(pos, piece->p3, piece->p1, map))
		return (0);
	//printf("p3 ok\n");
	if (!check_pos_part_piece(pos, piece->p4, piece->p1, map))
		return (0);
	//printf("p4 ok\n");
	return (1);
}

int	check_pos_part_piece(t_pos pos, t_pos part, t_pos p1, t_map map)
{
	t_pos	tmp;

	tmp.x = part.x - p1.x;
	tmp.y = part.y - p1.y;
	//printf("valeur crocher [%d][%d] et taille map ->%d\n",pos.y + tmp.y, pos.x + tmp.x, map.len);
	if (pos.x + tmp.x < 0 || pos.x + tmp.x > map.len)
	{
		//printf("x ->%d\n", pos.x + tmp.x);
		//printf("de passement\n");
		return (0);
	}
	else if (pos.y + tmp.y < 0 || pos.y + tmp.y > map.len)
	{
		//printf("depassement sur y\n");
		return (0);
	}
	else if (map.map[pos.y + tmp.y][pos.x + tmp.x] != '.')
	{
		return (0);
	}
	else
		return (1);
}

void	do_put_piece(t_map	**map, t_piece *piece, t_pos pos)
{
	(*map)->map[pos.y - 1][pos.x - 1] = piece->c;
	(*map)->map[pos.y + piece->p2.y - 2][pos.x + piece->p2.x - 2] = piece->c;
	(*map)->map[pos.y + piece->p3.y - 2][pos.x + piece->p3.x - 2] = piece->c;
	(*map)->map[pos.y + piece->p4.y - 2][pos.x + piece->p4.x - 2] = piece->c;
	
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

t_pos	init_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}
