/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:00:44 by lfouquet          #+#    #+#             */
/*   Updated: 2016/02/22 18:43:07 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_structure_fillit(t_fillit *fillit)
{
	fillit->nb_piece = 0;
	fillit->pieces = NULL;
}

void	init_sequence_fillit(int ac, char **av, t_fillit *fillit)
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
			fillit->pieces = get_pieces(pieces);
			fillit->nb_piece = count_piece(pieces);
			free(pieces);
		}
		else
			set_error_quit("Read error", fillit);
	}
	else
		set_error_quit("Open error", fillit);
}

//void	launch_sequence(t_fillit *fillit){}

void	free_fillit(t_fillit *fillit)
{
	int	i;

	i = 0;
	while (i < fillit->nb_piece)
		free(fillit->pieces[i++]);
	if (fillit->nb_piece)
	{
		free(fillit->pieces);
		fillit->pieces = NULL;
	}
}

void	set_error_quit(char *str, t_fillit *fillit)
{
	if (str)
		ft_putendl(str);
	free_fillit(fillit);
	exit(0);
}