/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:02:40 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/22 20:50:23 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	initlemin(t_lemin *data)
{
	data->n_ants = 0;

	data->connection = NULL;

	data->anthill.n_room = 0;
	data->anthill.head = NULL;
	data->anthill.start = NULL;
	data->anthill.end = NULL;
}

t_room	*initroom(char **split)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(*room))))
		print_error("Memory Allocation Error, Type 'Room'");
	room->room = split[0];
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	room->next = NULL;
	return (room);
}