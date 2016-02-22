/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:52:17 by bchevali          #+#    #+#             */
/*   Updated: 2016/02/22 18:27:35 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include "../libft/libft.h"

//care
#include <stdio.h>
//care

#define USAGE "usage: ./fillit <File>"

typedef struct		s_fillit
{
	int				nb_piece;
	char			**pieces;
}					t_fillit;

/*
**	check_file.c
*/
int		nbsign_adj(char *piece, int *tmp);
int		form_sign(char *piece);
int		check_char(char *piece);
int		check_pieces(char **tab_piece);
int		check_valid(int *tab);

/*
**	read_file.c
*/
void		replace_char(char **tab_piece);
char		**split_pieces(char *pieces);
char		**get_pieces(char *pieces);
int			count_piece(char *pieces);
int			get_file(int fd, char **pieces);

/*
**	sequence.c
*/
void	init_structure_fillit(t_fillit *fillit);
void	init_sequence_fillit(int ac, char **av, t_fillit *fillit);
void	launch_sequence(t_fillit *fillit);
void	free_fillit(t_fillit *fillit);
void	set_error_quit(char *str, t_fillit *fillit);

/*
**	opt_CHECK.c
*/
void		init_at_zero(int *tab, int opt);
int			sub_one(int index, char *piece, int *check, int *pos);
int			sub_five(int index, char *piece, int *check, int *pos);
int			add_one(int index, char *piece, int *check, int *pos);
int			add_five(int index, char *piece, int *check, int *pos);
#endif