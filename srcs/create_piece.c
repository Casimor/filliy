/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:59:50 by lfouquet          #+#    #+#             */
/*   Updated: 2016/03/04 18:11:57 by lfouquet         ###   ########.fr       */
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
	set_width_height_piece(&piece);
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

void	set_width_height_piece(t_piece **piece)
{
	int	max;
	int	min;

	min = (*piece)->p1.x;
	min = (min > (*piece)->p2.x) ? (*piece)->p2.x : min;
	min = (min > (*piece)->p3.x) ? (*piece)->p3.x : min;
	min = (min > (*piece)->p4.x) ? (*piece)->p4.x : min;
	max = (*piece)->p1.x;
	max = (max < (*piece)->p2.x) ? (*piece)->p2.x : max;
	max = (max < (*piece)->p3.x) ? (*piece)->p3.x : max;
	max = (max < (*piece)->p4.x) ? (*piece)->p4.x : max;
	(*piece)->width = max - min + 1;
	min = (*piece)->p1.x;
	min = (min > (*piece)->p2.y) ? (*piece)->p2.y : min;
	min = (min > (*piece)->p3.y) ? (*piece)->p3.y : min;
	min = (min > (*piece)->p4.y) ? (*piece)->p4.y : min;
	max = (*piece)->p1.x;
	max = (max < (*piece)->p2.y) ? (*piece)->p2.y : max;
	max = (max < (*piece)->p3.y) ? (*piece)->p3.y : max;
	max = (max < (*piece)->p4.y) ? (*piece)->p4.y : max;
	(*piece)->height = max - min + 1;
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
