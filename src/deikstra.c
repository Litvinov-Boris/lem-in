/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deikstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:13:59 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/22 14:38:41 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_subroom	*search_min(t_lemin *data)
{
	t_list		*work;
	t_subroom	*sing;
	int			min;

	min = INT_MAX;
	work = data->rooms;
	sing = NULL;
	while (work != NULL)
	{
		if (((t_room*)work->content)->in->visited == 0 &&
		((t_room*)work->content)->in->distance < min)
		{
			sing = ((t_room*)work->content)->in;
			min = ((t_room*)work->content)->in->distance;
		}
		if (((t_room*)work->content)->out->distance < min &&
					((t_room*)work->content)->out->visited == 0)
		{
			sing = ((t_room*)work->content)->out;
			min = ((t_room*)work->content)->out->distance;
		}
		work = work->next;
	}
	return (sing);
}

void		change_dist(t_subroom *data)
{
	t_list	*work;

	work = data->links;
	while (work != NULL)
	{
		if ((((t_tube*)work->content)->weight + data->distance) <
		((t_tube*)work->content)->link->distance)
		{
			((t_tube*)work->content)->link->distance =
			((t_tube*)work->content)->weight + data->distance;
			((t_tube*)work->content)->link->parent = data;
		}
		work = work->next;
	}
	data->visited = 1;
}

void		deikstra(t_lemin *data)
{
	t_subroom *work;

	zero_subrooms_deikstra(data);
	while ((work = search_min(data)))
	{
		change_dist(work);
	}
}
