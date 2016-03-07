/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:52:17 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/07 16:10:41 by lfouquet         ###   ########.fr       */
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
	int				put;
	int				width;
	int				height;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_map
{
	int				len;
	char			**map;
}					t_map;

/*
** main.c
*/
void	print_pieces(t_piece *pieces);
void	print_piece(t_piece *piece, int num);

/*
**	create_piece.c
*/
t_piece *create_piece(char *str, int value);
void	init_pos_part_piece(char *str, t_piece **piece);
void 	set_pos_part_piece(t_piece **piece);
t_pos	calc_pos_part(int x);
void	set_width_height_piece(t_piece **piece);
//Ailleurs
int		get_size_square_theoretic(int nb);

/*
**	piece_tool.c
*/
int		can_put_piece(t_map map, t_piece *piece, t_pos pos);
int		check_pos_part_piece(t_pos pos, t_pos part, t_map map);
void	do_put_piece(t_map	**map, t_piece *piece, t_pos pos);
int		all_pieces_puted(t_piece *piece);
t_pos	init_pos(int x, int y);

/*
**	solve_map.c
*/
int		solve_square(t_map *map, t_fillit *fillit, int len);
int		solve2(t_map	*map, t_piece *piece);
int		set_next_pos(t_map *map, t_pos *pos);

/*
**	solve3.c
*/

/*
**	map.c
*/
t_map	init_map(int len);
char	*init_value_line_map(char *line, int len);
void	print_map(t_map map);
void	free_map(t_map map);
int		set_pos_free(t_map map, t_pos *pos);
void	delete_piece_map(t_map *map, char c);


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
void	init_sequence(int ac, char **av, t_fillit *fillit);
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