/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 05:11:55 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/03 06:48:33 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	move_to_next_room(t_room *src, t_room *dst)
{
	if (src->ant)
	{
		dst->ant = src->ant;
		src->ant = 0;
		printf("L%d-%s ", dst->ant, dst->name);
	}
}

void	moving(t_room *room)
{
	if (room->thread == NULL)
	{
		room->ant = 0;
		return;
	}
	moving(room->thread);
	if (room->thread->ant == 0)
		move_to_next_room(room, room->thread);
}

int		path_len(t_room *r)
{
	t_room *tmp;
	int i;

	tmp = r;
	i = 0;
	while(tmp)
	{
		i++;
		tmp = tmp->thread;
	}
	return (i);
}

void	print_ant(t_lem *l)
{
	int i;
	int len;
	int new_ant;

	new_ant = 1;
	i = 1;
	len = path_len(l->room_list);
	while (i-len <= (l->ant - 2))
	{	

		if (i <= l->ant)
			l->room_list->ant = i;
		moving(l->room_list);
		i++;
		printf("\n");
	}
}
