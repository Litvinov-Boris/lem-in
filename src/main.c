/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:34:18 by svivienn          #+#    #+#             */
/*   Updated: 2019/11/26 22:43:28 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	t_lemin	data;

	fd = open("./test", O_RDWR);
	init_lemin(&data);
	//data.rooms[100].x = 100;
	read_map(&data);
	close(fd);
	return (0);
}