/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:02:40 by svivienn          #+#    #+#             */
/*   Updated: 2019/11/05 18:21:46 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	initlemin(t_lemin *data)
{
	ft_memset(data, 0, sizeof(t_lemin));
}

t_room	*initroom(char **split)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(*room))))
		print_error("Memory Allocation Error, Type 'Room'");
	ft_memset(room, 0, sizeof(t_room));
	room->room = split[0];
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	return (room);
}

void	init_searching(t_lemin *data)
{
	t_room	*save;
	int i;

	if(!(data->searching = (t_in_out_put*)malloc(sizeof(t_in_out_put) * 
		(data->anthill.n_room * 2))))
		print_error("Memory Allocation Error, Type 'Searching'");
	ft_memset(data->searching, 0, sizeof(t_in_out_put) * 
		(data->anthill.n_room * 2));
	save = data->anthill.head;
	i = 0;
	while (save != NULL)
	{
		save->input = data->searching + i;
		save->output = data->searching + i + 1;
		i + 2;
		if (data->anthill.head = save)
			save->input->path = 0;
		else
		{
			save->input->path = 10000000000000000;
			save->output->path = 10000000000000000;
		}
	}
}