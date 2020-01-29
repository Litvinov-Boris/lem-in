/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:09:24 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/28 16:30:00 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_subroom	*initsubroom(int type, t_room *master)
{
	t_subroom *subroom;

	if (!(subroom = (t_subroom*)malloc(sizeof(t_subroom))))
		error("Malloc Allocation Error: Suboom");
	bzero(subroom, sizeof(t_subroom));
	subroom->type = type;
	subroom->master = master;
	return (subroom);
}

t_tube				*init_tube(int weight, t_subroom *link)
{
	t_tube	*tube;

	tube = (t_tube*)malloc(sizeof(t_tube));
	tube->link = link;
	tube->weight = weight;
	tube->turn = 0;
	return (tube);
}

t_room				*init_room(char *str)
{
	t_room	*room;
	char	**work;

	if ((work = ft_strsplit(str, ' ')) == NULL)
		error("Malloc Allocation Error: Strsplit");
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		error("Malloc Allocation Error: Room");
	bzero(room, sizeof(t_room));
	room->name = work[0];
	room->x = ft_atoi(work[1]);
	room->y = ft_atoi(work[2]);
	free(work[1]);
	free(work[2]);
	free(work);
	room->in = initsubroom(IN, room);
	room->out = initsubroom(OUT, room);
	if (!(room->in->links = ft_lstnew(0, 0)))
		error("Malloc Allocation Error: List");
	room->in->links->content = init_tube(0, room->out);
	return (room);
}
