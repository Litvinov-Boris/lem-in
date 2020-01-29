/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:41:14 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/29 01:11:31 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error(char *str)
{
	perror(str);
	exit(1);
}

int		is_replay(t_lemin *data, t_room *room)
{
	t_room	*work;
	t_list	*work2;

	if (data && data->rooms && data->rooms->content)
	{
		work = data->rooms->content;
		work2 = data->rooms;
		while (work2 != NULL)
		{
			if (work->name == room->name || (work->x == room->x &&
				work->y == room->y))
				return (1);
			work2 = work2->next;
			if (work2 != NULL)
				work = work2->content;
		}
		return (0);
	}
	return (0);
}

t_room	*search_room(t_lemin *data, char *room)
{
	t_list	*result;

	result = data->rooms;
	while (result && ft_strcmp(((t_room*)result->content)->name, room))
		result = result->next;
	if (result)
		return (result->content);
	else
		return (NULL);
}

int		is_replay_tube(t_room *room1, t_room *room2)
{
	t_list	*work;

	work = room1->out->links;
	while (work && ((t_tube*)work->content)->link != room2->in)
		work = work->next;
	if (work != NULL)
		return (1);
	work = room2->out->links;
	while (work && ((t_tube*)work->content)->link != room1->in)
		work = work->next;
	if (work != NULL)
		return (1);
	return (0);
}

void	zero_subrooms_deikstra(t_lemin *data)
{
	t_list	*work;

	work = data->rooms;
	while (work != NULL)
	{
		((t_room*)work->content)->in->visited = 0;
		((t_room*)work->content)->out->visited = 0;
		((t_room*)work->content)->in->distance = INT_MAX;
		((t_room*)work->content)->out->distance = INT_MAX;
		((t_room*)work->content)->in->parent = NULL;
		((t_room*)work->content)->out->parent = NULL;
		((t_room*)work->content)->child_new = NULL;
		((t_room*)work->content)->parent_new = NULL;
		work = work->next;
	}
	data->start->in->distance = 0;
}
