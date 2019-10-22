/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:53:35 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/22 21:14:02 by svivienn         ###   ########.fr       */
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
		room_parcer2(str, &(data->anthill));
	else if (line_mode == START)
		stop_parcer(&(data->anthill), START);
	else if (line_mode == END)
		stop_parcer(&(data->anthill), END);
	else if (line_mode == TUBE)
	{
		*mode = TUBE;
	}
	else
		print_error("Invalid Input");
}

void	tube_parser()
{
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
			tube_parser();//парсер труб
		free(line);
	}
}
