/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:09:24 by svivienn          #+#    #+#             */
/*   Updated: 2019/11/26 22:27:03 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_lemin(t_lemin *data)
{
	bzero(data, sizeof(t_lemin));
	if ((data->rooms = (t_room*)malloc(sizeof(t_room) * 100)) == NULL)
		error("Memory Allocation Error, Type 'Rooms'");
	bzero(data->rooms, sizeof(t_room) * 100);
}