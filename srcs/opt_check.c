/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:08:38 by bchevali          #+#    #+#             */
/*   Updated: 2016/02/08 16:37:47 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sub_one(int index, char *piece, int *check, int *pos)
{
	int		i;

	i = 0;
	if (piece[index - 1] && piece[index - 1] == '#')
	{
		while (i < 4)
		{
			if ((index - 1) == pos[i] && check[i])
				return (1);
			++i;
		}
	}
	return (0);
}

int		sub_five(int index, char *piece, int *check, int *pos)
{
	int		i;

	i = 0;
	if (piece[index - 5] && piece[index - 5] == '#')
	{
		while (i < 4)
		{
			if ((index - 5) == pos[i] && check[i])
				return (1);
			++i;
		}
	}
	return (0);
}

int		add_one(int index, char *piece, int *check, int *pos)
{
	int		i;

	i = 0;
	if (piece[index + 1] && piece[index + 1] == '#')
	{
		while (i < 4)
		{
			if ((index + 1) == pos[i] && check[i])
				return (1);
			++i;
		}
	}
	return (0);
}

int		add_five(int index, char *piece, int *check, int *pos)
{
	int		i;

	i = 0;
	if (piece[index + 5] && piece[index + 5] == '#')
	{
		while (i < 4)
		{
			if ((index + 5) == pos[i] && check[i])
				return (1);
			++i;
		}
	}
	return (0);
}
