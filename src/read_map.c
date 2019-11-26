/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:32:02 by svivienn          #+#    #+#             */
/*   Updated: 2019/11/26 22:42:06 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ants_parser(int line_mode, t_lemin *data, char *str, int *mode)
{
	if (line_mode != ANTS)
		error("Invalid Input");
	else
	{
		data->n_ants = ft_atoi(str);
		*mode = ROOM;
	}
	
}
void		read_map(t_lemin *data)
{
	int		mode;
	char	*line;
	int		ret;
	int		linemode;

	mode = ANTS;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			error("Read Error");
		else if ((linemode = is_valid(line)) == COMENT);
		else if (mode == ANTS)
			ants_parser(linemode, data, line, &mode);
		else if (mode == ROOM);
		else if (mode == TUBE);
		free (line);
	}
}