/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:34:18 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/22 14:33:34 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	t_lemin	data;

	fd = open("./test", O_RDWR);//for tests
	bzero(&data, sizeof(t_lemin));//обнуление инфы по всему
	read_map(&data);//собирает как надо
	if (data.start == NULL || data.end == NULL)
		error("Invalid Input");
	deikstra(&data);
	t_list *list = data.rooms;
	t_room *room;
	t_list *list2;
	t_tube *tube;
	while (list != NULL)
	{
		room = list->content;
		printf("%s\n", room->name);
		if (room->in->parent)
			printf("in parent: %s-%i", room->in->parent->master->name, room->in->parent->type);
		if (room->out->parent)
			printf("out parent: %s-%i", room->out->parent->master->name, room->out->parent->type);
		/*list2 = room->in->links;
		while (list2 != NULL)
		{
			tube = list2->content;
			printf ("%s_%i_%i, ", tube->link->master->name, tube->link->type, tube->weight);
			list2 = list2->next;
		}
		printf("\n");
		list2 = room->out->links;
		while (list2 != NULL)
		{
			tube = list2->content;
			printf ("%s_%i_%i, ", tube->link->master->name, tube->link->type, tube->weight);
			list2 = list2->next;
		}*/
		printf("\n");
		printf("\n");
		list = list->next;
	}
	close(fd);//for tests
	return (0);
}