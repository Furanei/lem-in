/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 00:30:50 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/02 05:10:51 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		mark_room(t_room *room, int i)
{
	room->file = i + 1;
}

void		soluce(t_room *room, t_room *order)
{
	int lo;
	int nb;

	nb = 0;
	lo = room->file;
	while (lo--)
	{
		nb = 0;
		order->thread = room;
		order = order->thread;
		while (room->pipe[nb])
		{
			if (room->pipe[nb]->file == lo)
				room = room->pipe[nb];
			nb++;
		}
	}
	order->thread = NULL;
}

t_room		*to_thread(t_room *file)
{
	t_room	*tmp;
	int i;

	i = 0;
	tmp = file;
	mark_room(file, 0);
	while (file)
	{
		i = 0;
		if (file->spe & START)
			return (file);
		while (file->pipe[i])
		{
			if (!file->pipe[i]->file)
			{
				tmp->thread = file->pipe[i];
				mark_room(file->pipe[i], file->file);
				tmp = tmp->thread;
			}
			i++;
		}
		file = file->thread;
	}
	ft_error_info(INFO, "NO FOUND :(");
	return (0);
}

void		algo(t_room *s, t_lem *l)
{
	t_room	*file;

	file = s;
	soluce(to_thread(&*file), &*l->room_list);
}

void		start_algo(t_lem *l)
{
	t_room *tmp;

	tmp = l->room_list;
	while(tmp)
	{
		if (tmp->spe & END)
		{
			break;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		ft_error_info(INFO, "no_room_start");
	algo(tmp, &*l);
}
