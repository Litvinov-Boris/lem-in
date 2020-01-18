/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:09:24 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/18 20:35:50 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*init_room(char *str)
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
	room->in.master = room;
	room->out.master = room;
	if (!(room->in.links = ft_lstnew(&(room->out), sizeof(&(room->out)))))
		error("Malloc Allocation Error: List");
	return(room);
}