/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:59:50 by lfouquet          #+#    #+#             */
/*   Updated: 2016/02/25 18:37:42 by lfouquet         ###   ########.fr       */
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
	piece->put = 0;
	return (piece);
}

void	set_pos_part_piece(char *str, t_piece **piece)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			k++;
		else if (str[i] == '#')
		{
			if (j == 0)
				(*piece)->p1 = calc_pos_part(i + 1 - k);
			else if (j == 1)
				(*piece)->p2 = calc_pos_part(i + 1 - k);
			else if (j == 2)
				(*piece)->p3 = calc_pos_part(i + 1 - k);
			else
				(*piece)->p4 = calc_pos_part(i + 1 - k);
			j++;
		}
		i++;
	}
}

t_pos	calc_pos_part(int x)
{
	t_pos	part;

	part.x = (x <= 4) ? x : (x % 4);
	part.y = (x / 5) + 1;
	return (part);
}

int	get_size_square_theoretic(int nb)
{
	int	size;
	int	i;

	i = 2;
	size = nb * 4;
	while (42)
	{
		if (size <= i * i)
			return (i);
		i++;
	}
}
