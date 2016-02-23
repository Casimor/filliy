/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:50:52 by bchevali          #+#    #+#             */
/*   Updated: 2016/02/23 17:12:05 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int ac, char **av)
{
	t_fillit	fillit;

	init_structure_fillit(&fillit);
	init_sequence_fillit(--ac, av, &fillit);
	print_pieces(fillit.pieces);
	//launch_sequence_fillit(&fillit);
	free_fillit(&fillit);
	return (0);
}

void	print_pieces(t_piece *pieces)
{
	int	i;

	i = 1;
	while (pieces->next)
	{
		printf("-- Piece number %d\n", i);
		printf("--- p1: x->%d, y->%d\n", pieces->p1.x, pieces->p1.y);
		printf("--- p2: x->%d, y->%d\n", pieces->p2.x, pieces->p2.y);
		printf("--- p3: x->%d, y->%d\n", pieces->p3.x, pieces->p3.y);
		printf("--- p4: x->%d, y->%d\n", pieces->p4.x, pieces->p4.y);
		printf("----- valeur de la lettre ->%c\n\n", pieces->c);
		pieces = pieces->next;
		i++;
	}

		printf("-- Piece number %d\n", i);
		printf("--- p1: x->%d, y->%d\n", pieces->p1.x, pieces->p1.y);
		printf("--- p2: x->%d, y->%d\n", pieces->p2.x, pieces->p2.y);
		printf("--- p3: x->%d, y->%d\n", pieces->p3.x, pieces->p3.y);
		printf("--- p4: x->%d, y->%d\n", pieces->p4.x, pieces->p4.y);
		printf("----- valeur de la lettre ->%c\n\n", pieces->c);
}
