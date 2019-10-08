/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:02:40 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/08 16:41:41 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	initlemin(t_lemin *data)
{
	data->n_ants = 0;
	data->connection = NULL;
	data->anthill.n_room = 0;
	data->anthill.head = NULL;
	data->anthill.tail = NULL;
	data->anthill.flag_init = 0;
}

t_room	*initroom()
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(*room))))
		print_error("Memory Allocation Error, Type 'Room'");
	room->room = NULL;
	room->x = 0;
	room->y = 0;
	room->next = NULL;
	return (room);
}