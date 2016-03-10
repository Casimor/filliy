/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:17:52 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/10 15:32:56 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	replace_char(char **tab_piece)
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

char	**split_pieces(char *pieces)
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
	return (tab_piece);
}

int		count_piece(char *pieces)
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

int		get_pieces(char *pieces, t_piece **piece)
{
	char	**tab_piece;
	int		nb_piece;

	nb_piece = 0;
	tab_piece = split_pieces(pieces);
	if (!tab_piece)
		return (0);
	if (check_pieces(tab_piece))
	{
		*piece = format_pieces_from_char(tab_piece, count_piece(pieces));
		ft_free_tab(tab_piece);
		return (1);
	}
	else
	{
		ft_free_tab(tab_piece);
		return (0);
	}
}

int		get_file(int fd, char **pieces)
{
	int			i;
	ssize_t		ret;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];

	i = 0;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!*pieces)
			*pieces = ft_strdup(buf);
		else
		{
			tmp = *pieces;
			*pieces = ft_strjoin(*pieces, buf);
		}
		free(tmp);
	}
	if (ret == -1)
		return (0);
	return (1);
}
