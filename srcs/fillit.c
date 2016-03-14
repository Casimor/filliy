/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:06:42 by bchevali          #+#    #+#             */
/*   Updated: 2016/03/14 12:15:43 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fillit(char **av)
{
	t_fillit	fillit;

	ft_bzero(&fillit, sizeof(t_fillit));
	init_sequence(av, &fillit);
	launch_sequence(&fillit);
	free_fillit(&fillit);
}
