/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:41:14 by svivienn          #+#    #+#             */
/*   Updated: 2019/11/06 20:56:40 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error(char *str)
{
	perror(str);
	exit(1);
}

void	*ft_realloc(void *data, size_t new_size, size_t old_size)
{
	void	*t;

	if (new_size > old_size)
	{
		t = malloc(new_size);
		ft_memset(t, 0, new_size);
		if (data)
			ft_memcpy(t, data, old_size);
		return (t);
	}
	return (NULL);
}