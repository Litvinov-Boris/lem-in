/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:58:19 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/15 18:02:39 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_error(char *str)
{
	perror(str);
	exit(1);
}

void	free_split(char **split)
{
	char **save;

	if (split && *split)
	{
		save = &split[1];
		while (*save != NULL)
		{
			free(*save);
			save++;
		}
		free(split);
	}
}