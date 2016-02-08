/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:52:17 by bchevali          #+#    #+#             */
/*   Updated: 2016/02/08 15:21:45 by bchevali         ###   ########.fr       */
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

void		fillit(char *file);
char		**read_file(char *pieces);
int			check_pieces(char **tab_pieces);

int		sub_one(int index, char *piece, int *check, int *pos);
int		sub_five(int index, char *piece, int *check, int *pos);
int		add_one(int index, char *piece, int *check, int *pos);
int		add_five(int index, char *piece, int *check, int *pos);
#endif