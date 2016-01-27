/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:10:56 by bchevali          #+#    #+#             */
/*   Updated: 2016/01/27 18:13:13 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	get_file(int fd, char **pieces)
{
	char		buf[BUFF_SIZE + 1];
	ssize_t		ret;
	int			i;

	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!*pieces)
			*pieces = ft_strdup(buf);
		else
			*pieces = ft_strjoin(*pieces, buf);
	}
	if (ret == -1)
		return (0);
	return (1);
}

void		fillit(char *file)
{
	int		fd;
	char	*pieces;
	char	**tab_piece;
	int		i;

	i = 0;
	pieces = 0;
	if((fd = open(file, O_RDONLY)) != -1)
	{
		if (get_file(fd, &pieces))
		{
			tab_piece = read_file(pieces);
			return ;
		}
		ft_putendl_fd("Read error", 2);
		return ;
	}
	ft_putendl_fd("Open error", 2);
}