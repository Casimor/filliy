/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:00:44 by lfouquet          #+#    #+#             */
/*   Updated: 2016/03/10 15:43:46 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_sequence(char **av, t_fillit *fillit)
{
	int		fd;
	char	*pieces;

	pieces = NULL;
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		if (get_file(fd, &pieces))
		{
			if (get_pieces(pieces, &(fillit->pieces)))
				fillit->nb_piece = count_piece(pieces);
			else
			{
				free(pieces);
				set_error_quit("error", fillit);
			}
			free(pieces);
		}
		else
			set_error_quit("error", fillit);
	}
	else
		set_error_quit("error", fillit);
}

void	launch_sequence(t_fillit *fillit)
{
	t_map	map;
	int		len;

	len = get_size_square_theoretic(fillit->nb_piece);
	while (42)
	{
		if (solve_square(&map, fillit, len))
			break ;
		len++;
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

void	set_error_quit(t_fillit *fillit)
{
	ft_putendl_fd("error", 2);
	free_fillit(fillit);
	exit(0);
}
