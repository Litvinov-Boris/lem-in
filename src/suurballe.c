/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:35:41 by svivienn          #+#    #+#             */
/*   Updated: 2020/01/29 02:34:09 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	search_for_turn(t_subroom *data, t_list **search,
	t_list **presearch)
{
	*search = data->parent->links;
	*presearch = NULL;
	if (((t_tube*)(*search)->content)->link != data)
	{
		while (*search && ((t_tube*)(*search)->content)->link != data)
		{
			*presearch = *search;
			*search = (*search)->next;
		}
		if (*search == NULL)
			error("Tube Not Found");
	}
}

static void	tube_turn(t_lemin *data, t_subroom *subroom)
{
	t_list		*search;
	t_list		*search1;
	t_list		*newtube;

	if (subroom != data->start->out && subroom != data->end->out)
	{
		search_for_turn(subroom, &search, &search1);
		if (((t_tube*)search->content)->turn == 0)
		{
			if (search1 == NULL)
				subroom->parent->links = search->next;
			else
				search1->next = search->next;
			newtube = ft_lstnew(0, 0);
			newtube->content = init_tube(-(((t_tube*)search->content)->weight),
				subroom->parent);
			((t_tube*)newtube->content)->turn = 1;
			ft_lstadd(&(subroom->links), newtube);
			free(search->content);
			free(search);
		}
	}
}

static void	homecoming(t_lemin *data)
{
	t_subroom	*room;

	room = data->end->out;
	while (room->parent)
	{
		tube_turn(data, room);
		if (room->master != room->parent->master)
		{
			room->master->parent_new = room->parent->master;
			room->parent->master->child_new = room->master;
		}
		room = room->parent;
	}
	data->start->parent_old = NULL;
	data->end->child_old = NULL;
}

static void	build_map(t_lemin *data)
{
	t_list *work;
	t_room *work1;

	homecoming(data);
	work = data->rooms;
	while (work != NULL)
	{
		work1 = work->content;
		if (work1->parent_old == NULL)
			work1->parent_old = work1->parent_new;
		else if (work1->parent_old == work1->child_new)
			work1->parent_old = work1->parent_new;
		if (work1->child_old == NULL)
			work1->child_old = work1->child_new;
		else if (work1->child_old == work1->parent_new)
			work1->child_old = work1->child_new;
		work = work->next;
	}
}

int			suurballe(t_lemin *data)
{
	deikstra(data);
	if (data->end->in->parent == NULL)
		error("Invalid Map");
	if (data->end->in->parent == data->start->out)
		return (1);
	data->sum_dist = data->n_ants + data->end->out->distance - 1;
	data->height = data->sum_dist;
	data->trails = 1;
	while (data->end->in->parent != NULL)
	{
		build_map(data);
		deikstra(data);
		if (((data->sum_dist + data->end->out->distance - 1) /
					(data->trails + 1)) < data->height)
		{
			data->sum_dist += data->end->out->distance - 1;
			data->trails++;
			data->height = data->sum_dist / data->trails;
		}
		else
		{
			break ;
		}
	}
	return (0);
}
