/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:53:35 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/08 22:22:33 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	parser(char *str, t_lemin *data)
{
	int stat;

	if ((stat = is_valid(str, data)) == -1)
		print_error("Invalid Input");
	else if (stat == ANTS)
		data->n_ants = ft_atoi(str);
	else if (stat == ROOM)
	{
	}
	else if (stat == TUBE)
	{
	}
}