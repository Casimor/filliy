/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:50:52 by bchevali          #+#    #+#             */
/*   Updated: 2016/01/25 14:13:17 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		usage(void)
{
	ft_putendl_fd("usage: ./fillit <File>", 2);
}

int				main(int ac, char **av)
{
	if (ac == 2)
		fillit(av[1]);
	else
		usage();
	return (0);
}