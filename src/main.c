/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:34:18 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/08 22:07:40 by svivienn         ###   ########.fr       */
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
	int fd = open("./test", O_RDWR);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			print_error("Read Error");
		parser(line, &data);
		free(line);
	}
	close(fd);
	return (0);
}