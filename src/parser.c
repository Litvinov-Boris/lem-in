/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:53:35 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/15 19:50:24 by svivienn         ###   ########.fr       */
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

void	room_parser()
{
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
			room_parser();//парсер комнат
		else if (mode == TUBE)
			tube_parser();//парсер труб
		free(line);
	}
}
