/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:32:02 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/20 00:04:36 by svivienn         ###   ########.fr       */
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

static void	start_end_parser(t_lemin *data, int *mode, int start_end)
{
	char	*line;
	int		line_mode;

	if ((get_next_line(fd, &line) <= 0) ||
		((line_mode = is_valid(line)) != ROOM))
		error("Invalid Input");
	room_parser(line_mode, data, line, mode);
	free(line);
	if (start_end == START)
		data->start = data->rooms->content;
	else
		data->end = data->rooms->content;
}

void	room_parser(int line_mode, t_lemin *data,char *str, int *mode)
{
	t_list *work;

	if (line_mode == ROOM)
	{
		if (!(work = ft_lstnew(0,0)))
			error("Malloc Allocation Error: List");
		work->content = init_room(str);
		if (is_replay(data, work->content))
			error("Invalid Input");
		if (data->rooms == NULL)
			data->rooms = work;
		else
			ft_lstadd(&(data->rooms), work);
	}
	else if ((line_mode == START && data->start == NULL) ||
		(line_mode == END && data->end == NULL))
		start_end_parser(data, mode, line_mode);
	else if (line_mode = TUBE)
	
	else
		error("Invalid Input");
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
		{
			room_parser(linemode, data, line, mode);
		}
		else if (mode == TUBE);
		free (line);
	}
}