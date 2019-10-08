/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correctly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:46:34 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/08 21:46:35 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	is_coment(char *str)
{
	if (str[0] == '#' && ft_strcmp(str, "##start") &&
							ft_strcmp(str, "##end"))
		return (1);
	else
		return (0);
}

int	is_ants(char *str)
{
	if (ft_countwords(str, ' ') == 1)
	{
		while (*str != '\0')
		{
			if (!(ft_isdigit(*str)))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}

int	is_room(char *str)
{
	if (ft_countwords(str, ' ') == 3)
	{
		if (*str != 'L' && *str != '#')
		{
			while (*str != ' ')
			{
				if (*str == '-')
					return (0);
				str++;
			}
			while (*str != '\0')
			{
				if (!(ft_isdigit(*str)) && *str != ' ')
					return (0);
				str++;
			}
			return (1);
		}
	}
	return (0);
}

int	is_tube(char *str)
{
	return ((ft_countwords(str, ' ') == 1 && ft_countwords(str, '-') == 2) ? 1 : 0);
}

int	is_valid(char *str, t_lemin *data)
{
	if (is_coment(str))
		return (0);
	else if (data->n_ants == 0 && is_ants(str))
		return (1);
	else if (is_room(str))
		return (2);
	else if (is_tube(str))
		return (3);
	else if (!ft_strcmp(str, "##start"))
		return (4);
	else if (!ft_strcmp(str, "##end"))
		return (5);
	else
		return (-1);
}