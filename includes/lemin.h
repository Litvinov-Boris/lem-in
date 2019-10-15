/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:33:27 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/15 19:45:40 by svivienn         ###   ########.fr       */
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

int fd;

typedef struct			s_room
{
	char				*room;
	int					x;
	int					y;
	struct s_room		*next;
}						t_room;

typedef struct	s_anthill
{
	t_room		*head;
	t_room		*tail;
	t_room		*end;
	char		flag_init;
	int			n_room;           
}				t_anthill;

typedef struct	s_lemin
{
	int			n_ants;
	t_anthill	anthill;
	char		ffull;
	int			**connection;
}               t_lemin;

void	print_error(char *str);
void	free_split(char **split);

void	initlemin(t_lemin *data);
t_room	*initroom();

int		is_coment(char *str);
int		is_ants(char *str);
int		is_room(char *str);
int		is_tube(char *str);
int		is_valid(char *str, t_lemin *data);

void	ants_parser(char *str, t_lemin *data, int line_mode, int *mode);
void	room_parser();
void	tube_parser();
void	parser(t_lemin *data);

#endif