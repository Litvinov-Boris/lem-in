/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:53:35 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/28 16:31:10 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ants_parser(char *str, t_lemin *data, int line_mode, int *mode)
{
	if (line_mode != ANTS)
		print_error("Invalid Input");
	else
	{
		data->n_ants = ft_atoi(str);
		*mode = ROOM;
	}
}

void	room_parser(int *mode, int line_mode, char *str, t_lemin *data)
{
	if (line_mode == ROOM)
		room_parser2(str, &(data->anthill));
	else if (line_mode == START)
		stop_parser(&(data->anthill), START);
	else if (line_mode == END)
		stop_parser(&(data->anthill), END);
	else if (line_mode == TUBE)
	{
		*mode = TUBE;
		tube_parser(line_mode, str, data);
	}
	else
		print_error("Invalid Input");
}

void	tube_parser(int line_mode, char *str, t_lemin *data)
{
	char	**split;
	t_room	*room1;
	t_room	*room2;

	if (line_mode != TUBE)
		print_error("Invalid Input");
	if (!(split = ft_strsplit(str, '-')))
		print_error("Memory Allocation Error, Type 'TUBE'");
	if (!(room1 = search_room(split[0], &(data->anthill))) ||
		!(room2 = search_room(split[1], &(data->anthill))))
		print_error("No Rum");
	if (room1 == room2)
		print_error("Singl Room");
	push_tube(room1, room2, &(data->tubes));
}

void	parser(t_lemin *data)
{
	int		mode;
	char	*line;
	int		ret;
	int		line_mode;

	mode = ANTS;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			print_error("Read Error");
		else if ((line_mode = is_valid(line, data)) == COMENT);
		else if (mode == ANTS)
			ants_parser(line, data, line_mode, &mode);
		else if (mode == ROOM)
			room_parser(&mode, line_mode, line, data);//парсер комнат
		else if (mode == TUBE)
			tube_parser(line_mode, line, data);//парсер труб
		free(line);
	}
}
