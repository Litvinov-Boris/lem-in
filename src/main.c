/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:34:18 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/20 21:02:10 by svivienn         ###   ########.fr       */
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
	bzero(&data, sizeof(t_lemin));//обнуление инфыпо всему
	read_map(&data);
	t_room *room = data.rooms;
	t_list *subroom;
	while(room!= NULL)
	{
		printf("%s:\nin:", room->name);
		subroom = room->in.links;
		while (subroom!= NULL)
		{
			printf("%s-in", subroom->content->master->name)
		}
	}
	close(fd);//for tests
	return (0);
}