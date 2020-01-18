/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:32:02 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/18 22:05:50 by svivienn         ###   ########.fr       */
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

static void	room_parser(int line_mode, t_lemin *data,char *str, int mode)
{
	t_list *work;

	if (line_mode == ROOM)
	{
		if (!(work = ft_lstnew(init_room(str), sizeof(t_room*))))
			error("Malloc Allocation Error: List");
		if (data->rooms == NULL)
			data->rooms = work;
		else
			ft_lstadd(&(data->rooms), work);
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
		else if (mode == ROOM)
			room_parser(linemode, data, line, mode);
		else if (mode == TUBE);
		free (line);
	}
}