/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:50:52 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/09 17:32:05 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
void	print_pieces(t_piece *pieces);
void	print_piece(t_piece *piece, int num);
#include <stdio.h>

int				main(int ac, char **av)
{
	t_fillit	fillit;

	init_structure_fillit(&fillit);
	init_sequence(--ac, av, &fillit);
	//print_pieces(fillit.pieces);
	launch_sequence(&fillit);
	free_fillit(&fillit);
	return (0);
}

void	print_pieces(t_piece *pieces)
 {
 	int	i;
 
 	i = 1;
 	while (pieces)
 	{
 		print_piece(pieces, i++);
 		pieces = pieces->next;
 	}
 }
 
void	print_piece(t_piece *piece, int num)
 {
 printf("-- Piece number %d\n", num);
 printf("--- p1: x->%d, y->%d\n", piece->p1.x, piece->p1.y);
 printf("--- p2: x->%d, y->%d\n", piece->p2.x, piece->p2.y);
 printf("--- p3: x->%d, y->%d\n", piece->p3.x, piece->p3.y);
 printf("--- p4: x->%d, y->%d\n", piece->p4.x, piece->p4.y);
 printf("----- valeur de la lettre ->%c\n", piece->c);
 printf(" height ->%d\n", piece->height);
 }
