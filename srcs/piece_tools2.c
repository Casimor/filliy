/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 19:38:58 by lfouquet          #+#    #+#             */
/*   Updated: 2016/03/07 20:01:43 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		set_pos_free(t_map map, t_pos *pos)
{
	int	i;
	int	j;

	i = pos->y - 1;
	j = pos->x - 1;
	if (pos->y == map.len && pos->x == map.len)
		return (0);
	while (i < map.len)
	{
		while (j < map.len)
		{
			if (map.map[i][j] == '.')
			{
				pos->x = j + 1;
				pos->y = i + 1;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		get_size_square_theoretic(int nb)
{
	int	size;
	int	i;

	i = 3;
	size = nb * 4;
	while (42)
	{
		if (size <= i * i)
			return (i);
		i++;
	}
}

t_piece	*format_pieces_from_char(char **tab, int nb)
{
	int			i;
	t_piece		*piece;

	i = 0;
	piece = NULL;
	while (i < nb)
	{
		add_piece_end(&piece, create_piece(tab[i], i));
		i++;
	}
	return (piece);
}

void	add_piece_end(t_piece **first, t_piece *piece)
{
	t_piece	*tmp;

	tmp = *first;
	if (!tmp)
		*first = piece;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = piece;
	}
}
