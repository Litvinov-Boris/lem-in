/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:41:14 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/20 19:32:25 by svivienn         ###   ########.fr       */
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

	work = room1->out.links;
	while (work && work->content != &(room2->in))
		work = work->next;
	if (work != NULL)
		return (1);
	work = room2->out.links;
	while (work && work->content != &(room1->in))
		work = work->next;
	if (work != NULL)
		return (1);
	return (0);
}