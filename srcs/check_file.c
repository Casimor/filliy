/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:46:02 by bchevali          #+#    #+#             */
/*   Updated: 2016/02/08 17:04:04 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		nbsign_adj(char *piece, int *tmp)
{
	int		i;
	int		j;
	int		end;
	int		check[4] = {1, 0, 0, 0};

	i = 1;
	j = 1;
	end = 0;
	while (i < 4)
	{
		if (sub_one(tmp[i], piece, check, tmp) && !check[i])
			check[i] = 1;
		else if (sub_five(tmp[i], piece, check, tmp) && !check[i])
			check[i] = 1;
		else if (add_one(tmp[i], piece, check, tmp) && !check[i])
			check[i] = 1;
		else if (add_five(tmp[i], piece, check, tmp) && !check[i])
			check[i] = 1;
		if (i == 3 && end < 2)
		{
			i = 0;
			end += 1;
		}
		++i;
	}
	while (j < 4)
	{
		if (!check[j])
			return (0);
		++j;
	}
	return (1);
}

static int		form_sign(char *piece)
{
	int		i;
	int		i2;
	int		ret;
	int		tab[4] = {0, 0, 0, 0};

	i = 0;
	i2 = 0;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			tab[i2] = i;
			++i2;
		}
		++i;
	}
	ret = nbsign_adj(piece, tab);
	return (ret);
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

int				check_pieces(char **tab_piece)
{
	int		i;

	i = 0;
	while (tab_piece[i])
	{
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
