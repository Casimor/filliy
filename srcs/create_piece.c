/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:59:50 by lfouquet          #+#    #+#             */
/*   Updated: 2016/02/23 17:19:28 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece *create_piece(char *str, int value)
{
	t_piece	*piece;

	piece = (t_piece*)malloc(sizeof(t_piece));
	if (!piece)
		return (NULL);
	else
		set_pos_part_piece(str, &piece);
	piece->next = NULL;
	piece->c = 'A' + value;
	return (piece);
}

void	set_pos_part_piece(char *str, t_piece **piece)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (j == 0)
				(*piece)->p1 = calc_pos_part(i);
			else if (j == 1)
				(*piece)->p2 = calc_pos_part(i);
			else if (j == 2)
				(*piece)->p3 = calc_pos_part(i);
			else
				(*piece)->p4 = calc_pos_part(i);
			j++;
		}
		i++;
	}
}

t_pos	calc_pos_part(int x)
{
	t_pos	part;

	part.x = ((x + 1) / 5 * 4 + (x + 1) % 5);
	part.y = (x / 5) + 1;
	return (part);
}
