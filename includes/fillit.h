/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:52:17 by bchevali          #+#    #+#             */
/*   Updated: 2016/02/23 17:18:21 by lfouquet         ###   ########.fr       */
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
	struct s_piece	*pieces;
}					t_fillit;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_piece
{
	t_pos			p1;
	t_pos			p2;
	t_pos			p3;
	t_pos			p4;
	char			c;
	struct s_piece	*next;
}					t_piece;

/*
** main.c
*/
void	print_pieces(t_piece *pieces);

/*
**	create_piece.c
*/
t_piece *create_piece(char *str, int value);
void	set_pos_part_piece(char *str, t_piece **piece);
t_pos	calc_pos_part(int x);


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
int			get_pieces(char *pieces, t_piece **piece);
int			count_piece(char *pieces);
int			get_file(int fd, char **pieces);

t_piece	*format_pieces_from_char(char **tab, int nb);
void	add_piece_end(t_piece **first, t_piece *piece);

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