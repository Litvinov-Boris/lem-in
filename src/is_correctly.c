/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correctly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:46:34 by svivienn          #+#    #+#             */
/*   Updated: 2019/11/06 17:37:55 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	is_coment(char *str)
{
	if (str[0] == '#' && ft_strcmp(str, "##start") &&
							ft_strcmp(str, "##end"))
		return (1);
	else
		return (0);
}

static int	is_ants(char *str)
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

static int	is_room(char *str)
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

static int	is_tube(char *str)
{
	return ((ft_countwords(str, ' ') == 1 && ft_countwords(str, '-') == 2) ?
				1 : 0);
}

int			is_valid(char *str)
{
	if (is_coment(str))
		return (COMENT);
	else if (is_ants(str))
		return (ANTS);
	else if (is_room(str))
		return (ROOM);
	else if (is_tube(str))
		return (TUBE);
	else if (!ft_strcmp(str, "##start"))
		return (START);
	else if (!ft_strcmp(str, "##end"))
		return (END);
	else
		return (-1);
}
