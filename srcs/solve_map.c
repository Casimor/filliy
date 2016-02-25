/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:26:25 by lfouquet          #+#    #+#             */
/*   Updated: 2016/02/25 18:50:57 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve_square(t_map *map, t_fillit *fillit, int len)
{
	*map = init_map(len);

	if (go_solve1(map, &fillit))
		return (1);
	else
	{
		printf("on free la map de taille ->%d\n", map->len);
		free_map(*map);
		return (0);
	}
}

int	go_solve1(t_map	*map, t_fillit **fillit)
{
	t_piece	*tmp;
	t_pos	pos;

	tmp = (*fillit)->pieces;
	while ((*fillit)->pieces)
	{
		pos = get_first_pos_map(*map);
		if (can_put_piece(*map, (*fillit)->pieces, pos))
		{
			do_put_piece(&map, (*fillit)->pieces, pos);
			//printf("une piece de mise\n");
			(*fillit)->pieces->put = 1;
		}
		(*fillit)->pieces = (*fillit)->pieces->next;
	}
	(*fillit)->pieces = tmp;
	if (all_pieces_puted(tmp))
	{
		printf("toute les pieces ont ete mise\n");
		return (1);
	}
	else
		return (0);
}