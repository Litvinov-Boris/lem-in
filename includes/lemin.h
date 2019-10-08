/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:33:27 by svivienn          #+#    #+#             */
/*   Updated: 2019/10/08 21:40:27 by svivienn         ###   ########.fr       */
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
	struct s_room		*next;
}				t_room;

typedef struct	s_anthill
{
	t_room		*head;
	t_room		*tail;
	char		flag_init;
	int			n_room;           
}				t_anthill;

typedef struct	s_lemin
{
	int			n_ants;
	t_anthill	anthill;
	int			**connection;
}               t_lemin;

void print_error(char *str);

void	initlemin(t_lemin *data);
t_room	*initroom();

//int parser(char *str);
int	is_coment(char *str);
int	is_ants(char *str);
int	is_room(char *str);
int	is_tube(char *str);
int	is_valid(char *str, t_lemin *data);

#endif