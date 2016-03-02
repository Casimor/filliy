/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:00:44 by lfouquet          #+#    #+#             */
/*   Updated: 2016/03/02 15:23:37 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_structure_fillit(t_fillit *fillit)
{
	fillit->nb_piece = 0;
	fillit->pieces = NULL;
}

void	init_sequence(int ac, char **av, t_fillit *fillit)
{
	int		fd;
	char	*pieces;

	pieces = NULL;
	if (ac != 1)
		set_error_quit(USAGE, fillit);
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		if (get_file(fd, &pieces))
		{
			if (get_pieces(pieces, &(fillit->pieces)))
				fillit->nb_piece = count_piece(pieces);
			else
			{
				free(pieces);
				set_error_quit("error pieces", fillit);
			}
			free(pieces);
		}
		else
			set_error_quit("Read error", fillit);
	}
	else
		set_error_quit("Open error", fillit);
}

void	launch_sequence(t_fillit *fillit)
{
	t_map	map;
	int		len;

	len = get_size_square_theoretic(fillit->nb_piece);

	int	i = 0;
	while (i < 1)
	{
		if (solve_square(&map, fillit, len))
			break ;
		len++;
		i++;
	}
	print_map(map);
	free_map(map);
}

void	free_fillit(t_fillit *fillit)
{
	t_piece	*tmp;

	tmp = NULL;
	while (fillit->pieces)
	{
		tmp = fillit->pieces;
		fillit->pieces = fillit->pieces->next;
		free(tmp);
	}
}

void	set_error_quit(char *str, t_fillit *fillit)
{
	if (str)
		ft_putendl(str);
	free_fillit(fillit);
	exit(0);
}