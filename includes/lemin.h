/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:33:27 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/29 00:43:43 by svivienn         ###   ########.fr       */
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
# include <limits.h>

# define COMENT	0
# define ANTS	1
# define ROOM	2
# define TUBE	3
# define START	4
# define END	5
# define IN		1
# define OUT	2

//hslartib

int							fd;

typedef struct s_room		t_room;
typedef struct s_lemin		t_lemin;
typedef struct s_subroom	t_subroom;
typedef struct s_tube		t_tube;

struct						s_tube
{
	t_subroom				*link;
	int						weight;
	int						turn;
};

struct						s_subroom
{
	int						type;
	t_list					*links;
	char					visited;
	t_room					*master;
	int						distance;
	struct s_subroom		*parent;
};

struct						s_room
{
	char					*name;
	int						x;
	int						y;
	t_subroom				*in;
	t_subroom				*out;
	struct s_room			*parent_old;
	struct s_room			*parent_new;
	struct s_room			*child_old;
	struct s_room			*child_new;
};

struct				s_lemin
{
	int						n_ants;
	int						sum_dist;
	int						trails;
	int						height;
	t_list					*rooms;
	t_room					*start;
	t_room					*end;
};

int							is_valid(char *str);

void						error(char *str);
int							is_replay(t_lemin *data, t_room *room);
t_room						*search_room(t_lemin *data, char *room);
int							is_replay_tube(t_room *room1, t_room *room2);
void						zero_subrooms_deikstra(t_lemin *data);

t_room						*init_room(char *str);
t_tube						*init_tube(int weight, t_subroom *link);

void						room_parser(int line_mode,
							t_lemin *data, char *str, int *mode);
void						read_map(t_lemin *data);

void						print_1_step(t_lemin *data);

void						deikstra(t_lemin *data);

int							suurballe(t_lemin *data);
#endif
