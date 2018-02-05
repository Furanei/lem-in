/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 00:30:50 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/05 03:26:41 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		mark_room(t_room *room, int i)
{
	room->file = i + 1;
}

void		soluce(t_room *room, t_room *rlst)
{
	int path_len;
	int nb;

	nb = 0;
	path_len = room->file;
	while (path_len--)
	{
		nb = 0;
		rlst->thread = room;
		rlst = rlst->thread;
		while (nb < room->npipe)
		{
			if (room->pipe[nb]->file == path_len)
				room = room->pipe[nb];
			nb++;
		}
	}
	rlst->thread = NULL;
}

/*
**creer des niveaux pour les salles a la meme distance de END.
*/

t_room		*to_thread(t_room *room)
{
	t_room	*tmp;
	int		i;

	tmp = room;
	mark_room(room, 0);
	while (room)
	{
		i = 0;
		if (room->spe & START)
			return (room);
		while (i < room->npipe)
		{
			if (room->pipe[i]->file == 0)
			{
				tmp->thread = room->pipe[i];
				mark_room(room->pipe[i], room->file);
				tmp = tmp->thread;
			}
			i++;
		}
		room = room->thread;
	}
	ft_error("ERROR (no path)");
	return (0);
}

void		algo(t_lem *l)
{
	t_room *tmp;

	tmp = l->room_list;
	while (tmp && !(tmp->spe & END))
		tmp = tmp->next;
	if (!tmp)
		ft_error("ERROR (end)");
	soluce(to_thread(tmp), &*l->room_list);
}
