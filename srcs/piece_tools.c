/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:05:02 by lfouquet          #+#    #+#             */
/*   Updated: 2016/02/25 17:41:30 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		put_piece(char **t, t_piece *piece, t_pos pos, int len)
{
	t_pos	tmp;

	if (t[pos.x][pos.y] != '.')
		return (0);
	if (!check_pos_part_piece(pos, piece->p2, piece->p1, t))
		return (0);
	if (!check_pos_part_piece(pos, piece->p3, piece->p1, t))
		return (0);
	if (!check_pos_part_piece(pos, piece->p4, piece->p1, t))
		return (0);
	return (1);





	printf("part 1 good\n");
	tmp.x = piece->p2.x - piece->p1.x;
	tmp.y = piece->p2.y - piece->p1.y;
	if (pos.x + tmp.x < 0 || pos.x + tmp.x > len)
		return (0);
	if (pos.y + tmp.y < 0 || pos.y + tmp.y > len)
		return (0);
	if (t[pos.x + tmp.x][pos.y + tmp.y] != '.')
		return (0);
	printf("part 2 good\n");
	tmp.x = piece->p3.x - piece->p1.x;
	tmp.y = piece->p3.y - piece->p1.y;
	if (pos.x + tmp.x < 0 || pos.x + tmp.x > len)
		return (0);
	if (pos.y + tmp.y < 0 || pos.y + tmp.y > len)
		return (0);
	if (t[pos.x + tmp.x][pos.y + tmp.y] != '.')
		return (0);
	printf("case 3 valeur ->%c\n", t[pos.x + tmp.x][pos.y + tmp.y]);
	printf("part 3 good\n");
	tmp.x = piece->p4.x - piece->p1.x;
	tmp.y = piece->p4.y - piece->p1.y;
	if (pos.x + tmp.x < 0 || pos.x + tmp.x > len)
		return (0);
	if (pos.y + tmp.y < 0 || pos.y + tmp.y > len)
		return (0);
	if (t[pos.x + tmp.x][pos.y + tmp.y] != '.')
	{
		printf("error\n");
		printf("valeur de x ->%d, valeur de y ->%d\n", pos.x + tmp.x, pos.y + tmp.y);
		printf("tmpx ->%d, tmpy ->%d, posx ->%d, posy ->%d\n", tmp.x, tmp.y, pos.x, pos.y);
		//printf("value case ->%c\n", t[pos.x + tmp.x][pos.y + tmp.y + 1]);
		//printf("value case ->%c\n", t[pos.x + tmp.x][pos.y + tmp.y + 1]);
		return (0);
	}
	printf("part 4 good\n");
	return (1);
}

int	check_pos_part_piece(t_pos pos, t_pos part, t_pos p1, int len, char **t)
{
	t_pos	tmp;

	tmp.x = part.x - p1.x;
	tmp.y = part.y - p1.y;
	if (pos.x + tmp.x < 0 || pos.x + tmp.x > len)
		return (0);
	else if (pos.y + tmp.y < 0 || pos.y + tmp.y > len)
		return (0);
	else if (t[pos.x + tmp.x][pos.y + tmp.y] != '.')
		return (0);
	else
		return (1);
}