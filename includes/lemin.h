/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:33:27 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/20 19:33:26 by svivienn         ###   ########.fr       */
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

int							fd;

/*typedef struct				s_list
{
	void					*data;
	struct s_list			*next;
}							t_list;*/

typedef struct				s_room
{
	char					*name;
	int						x;
	int						y;
	struct					s_subroom
	{
		t_list				*links;
		char				visited;
		struct s_room		*master;
		int					distance;
		struct s_subroom	*parent;
	}						in;
	struct s_subroom		out;
	struct s_room			*parent_old;
	struct s_room			*parent_new;
	struct s_room			*child_old;
	struct s_room			*child_new;
}							t_room;

typedef struct				s_lemin
{
	int						n_ants;
	int						height;
	t_list					*rooms;
	t_room					*start;
	t_room					*end;
}							t_lemin;

int							is_valid(char *str);

void						error(char *str);
int							is_replay(t_lemin *data, t_room *room);
t_room						*search_room(t_lemin *data, char *room);
int							is_replay_tube(t_room *room1, t_room *room2);

t_room						*init_room(char *str);

void						room_parser(int line_mode, t_lemin *data,char *str, int *mode);
void						read_map(t_lemin *data);
#endif
