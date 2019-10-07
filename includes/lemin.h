/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:33:27 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/07 21:36:32 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

typedef struct	s_room
{
	char		*room;
	int			x;
	int			y;
	t_room		*next;
}				t_room;

typedef struct	s_anthill
{
	t_room		*head;
}				t_anthill;

typedef struct	s_lemin
{
	int			n_ants;
	t_anthill	anthill;
	int			**connection;
}               t_lemin;

#endif