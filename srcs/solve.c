/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 00:30:50 by mbriffau          #+#    #+#             */
/*   Updated: 2018/03/06 00:06:34 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** recherche la salle avec la valeur n - 1 de la salle actuelle.
*/

t_room		*find_path(t_room *r1, int find)
{
	int		idx;

	idx = 0;
	while (idx < r1->npipe)
	{
		if (r1->pipe[idx]->file == find)
			return (r1->pipe[idx]);
		idx++;
	}
	ft_error("ERROR find_path");
	return (0);
}

t_room		*soluce(t_room *r1, t_room *rlst)
{
	int		path_len;
	t_room	*tmp;

	rlst = r1;
	tmp = rlst;
	path_len = r1->file;
	while (--path_len > 0)
	{
		r1 = find_path(r1, path_len);
		rlst->thread = r1;
		rlst = rlst->thread;
	}
	rlst->thread = NULL;
	rlst = tmp;
	return (rlst);
}

void		algo(t_lem *l)
{
	t_room *tmp;

	tmp = l->room_list;
	while (tmp && !(tmp->spe & END))
	{
		tmp = tmp->next;
	}
	(tmp == NULL) ? ft_error("ERROR (end)") : 0;
	l->room_list = soluce(mark_the_map(tmp), &*l->room_list);
}
