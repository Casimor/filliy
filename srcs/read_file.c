/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:17:52 by bchevali          #+#    #+#             */
/*   Updated: 2016/02/22 18:55:43 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		replace_char(char **tab_piece)
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

char		**split_pieces(char *pieces)
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

char			**get_pieces(char *pieces)
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

int	get_file(int fd, char **pieces)
{
	char		buf[BUFF_SIZE + 1];
	ssize_t		ret;
	int			i;
	char		*tmp;

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
