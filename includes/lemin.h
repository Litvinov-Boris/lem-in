/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:33:27 by svivienn          #+#    #+#             */
/*   Updated: 2019/11/26 22:42:04 by svivienn         ###   ########.fr       */
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

# define COMENT	0
# define ANTS	1
# define ROOM	2
# define TUBE	3
# define START	4
# define END	5

//hslartib

int fd; 

typedef struct	s_subroom
{
	int			n_step;
	void		*rooms;
	void		*parent;
	char		visit;
}				t_subroom;

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	t_subroom	in;
	t_subroom	out;
}				t_room;


typedef struct	s_lemin
{
	int			n_ants;
	int			n_rooms;
	t_room		*rooms;

}				t_lemin;


int	is_valid(char *str);

void	error(char *str);
void	*ft_realloc(void *data, size_t new_size, size_t old_size);

void	init_lemin(t_lemin *data);

void		read_map(t_lemin *data);
#endif
