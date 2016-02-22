/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:50:52 by bchevali          #+#    #+#             */
/*   Updated: 2016/02/22 18:31:49 by lfouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int ac, char **av)
{
	t_fillit	fillit;

	init_structure_fillit(&fillit);
	init_sequence_fillit(--ac, av, &fillit);
	//launch_sequence_fillit(&fillit);
	free_fillit(&fillit);
	return (0);
}
