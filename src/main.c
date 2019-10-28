/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:34:18 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/28 21:32:31 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	t_lemin data;
	int ret;
	char *line;

	initlemin(&data);
	fd = open("./test", O_RDWR);
	parser(&data);
	t_room *save;
	save = data.anthill.head;
	while (save != NULL)
	{
		printf ("%s %i %i\n", save->room, save->x, save->y);
		save = save->next;
	}
	t_tube *save1 = data.tubes;
	while (save1 != NULL)
	{
		printf ("%s - %s\n", save1->room1->room, save1->room2->room);
		save1 = save1->next;
	}
	close(fd);
	return (0);
}