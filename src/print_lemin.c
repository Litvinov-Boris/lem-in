/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lemin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:27:15 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/22 13:14:31 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_1_step(t_lemin *data)
{
	int i;

	i = 1;
	while (i < data->n_ants)
	{
		printf("L%i-%s, ", i, data->end->name);
	}
	printf("L%i-%s,\n", i, data->end->name);
}