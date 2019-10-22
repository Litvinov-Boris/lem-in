/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:27:30 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/22 21:12:26 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*room_parcer2(char *line, t_anthill *data)
{
	char 	**split;
	t_room	*room;
	t_room	*save;

	if (!(split = ft_strsplit(line, ' ')))
		print_error("Memory Allocation Error, Type 'Room'");
	room = initroom(split);
	free_split(split);
	if (data->head == NULL)
		data->head = room;
	else
	{
		save = data->head;
		while (save->next != NULL)
		{
			if (!ft_strcmp(save->room, room->room))
				print_error("Duplication Of Rooms");
			save = save->next;
		}
		save->next = room;
	}
	data->n_room++;
	return (room);
}

void	stop_parcer(t_anthill *data, int stat)
{
	char	*line;
	int ret;

	if (data->start != NULL && stat == START)
		print_error("Duplication Of Start");
	if (data->end != NULL && stat == END)
		print_error("Duplication Of End");
	ret = get_next_line(fd, &line);
	if (ret == -1)
		print_error("Read Error");
	if (stat == START)
		data->start = room_parcer2(line, data);
	else
		data->end = room_parcer2(line, data);
}