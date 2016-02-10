/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:17:52 by bchevali          #+#    #+#             */
/*   Updated: 2016/02/10 15:39:54 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		replace_char(char **tab_piece)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	c = 'A';
	while (tab_piece[i])
	{
		j = 0;
		while (tab_piece[i][j])
		{
			if (tab_piece[i][j] == '#')
				tab_piece[i][j] = c;
			++j;
		}
		++c;
		++i;
	}
}

static int		count_piece(char *pieces)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (pieces[i])
	{
		if (pieces[i] == '\n' && pieces[i + 1] == '\n')
			++j;
		i++;
	}
	return (j + 1);
}

static char		**split_pieces(char *pieces)
{
	char	**tab_piece;
	int		i;
	int		j;
	int		a;

	a = 0;
	i = 0;
	j = 0;
	tab_piece = (char**)ft_memalloc(sizeof(char*) * (count_piece(pieces) + 1));
	if (tab_piece)
	{
		while (pieces[i])
		{
			if (pieces[i] == '\n' && pieces[i + 1] == '\n')
			{
				tab_piece[a] = ft_strsub(pieces, j, i - j + 1);
				j = i + 2;
				++a;
			}
			++i;
		}
		tab_piece[a] = ft_strsub(pieces, j, i - j);
	}
	free(pieces);
	return (tab_piece);
}

char			**read_file(char *pieces)
{
	char	**tab_piece;

	tab_piece = split_pieces(pieces);
	if (tab_piece)
	{
		if (check_pieces(tab_piece))
			replace_char(tab_piece);
		else
		{
			ft_free_tab(tab_piece);
			ft_putendl_fd("error", 2);
			return (NULL);
		}
	}
	return (tab_piece);
}
