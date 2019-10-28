/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:27:30 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/28 16:12:05 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*room_parser2(char *line, t_anthill *data)
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

void	stop_parser(t_anthill *data, int stat)
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

t_room	*search_room(char *str, t_anthill *data)
{
	t_room *save;

	save = data->head;
	while (save != NULL)
	{
		if (!ft_strcmp(str, save->room))
			return(save);
		save = save->next;
	}
	return (NULL);
}

void	push_tube(t_tube *room1, t_tube *room2, t_tube *head)
{
	t_tube	*room;
	t_tube	*save;

	room = (t_tube*)malloc(sizeof(t_tube));
	room->room1 = room1;
	room->room2 = room2;
	room->next = NULL;
	if (head = NULL)
		head = room;
	else
	{
		save = head;
		while (save->next != NULL)
			if (save->room1 == room->room1 && save->room2 == room->room2)
				print_error("")
	}
	
}