/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:46:02 by bchevali          #+#    #+#             */
/*   Updated: 2016/01/28 17:44:10 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		nbsign_adj(char *piece, int i, int nb_found)
{
	if ((piece[i + 1] && piece[i + 1] == '#') || nb_found == 4)
		return (1);
	if (piece[i + 5] && piece[i + 5] == '#')
		return (1);
	return (0);
}

static int		form_sign(char *piece)
{
	int		i;
	int		nb_found;

	i = 0;
	nb_found = 0;
	while (piece[i])
	{
		while (piece[i] == '#')
		{
			++nb_found;
			i = nbsign_adj(piece, i, nb_found))
		}
		if ()
		++i;
	}
	return (1);
}

static int		check_char(char *piece)
{
	int		i;
	int		nb_line;
	int		dot;

	nb_line = 0;
	dot = 0;
	i = 0;
	while (piece[i])
	{
		if (piece[i] != '.' && piece[i] != '#' && piece[i] != '\n')
			return (0);
		if (piece[i] == '\n')
			++nb_line;
		if (piece[i] == '.')
			++dot;
		++i;
	}
	if (i != 20 || nb_line != 4 || dot != 12)
		return (0);
	return (1);
}

int		check_pieces(char **tab_piece)
{
	int		i;

	i = 0;
	while (tab_piece[i])
	{
		printf("%d\n", i);
		if (!check_char(tab_piece[i]))
			return (0);
		if (!form_sign(tab_piece[i]))
			return (0);
		++i;
	}
	if (i > 26)
		return (0);
	return (1);
}