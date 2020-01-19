/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:41:14 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/19 23:59:02 by svivienn         ###   ########.fr       */
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