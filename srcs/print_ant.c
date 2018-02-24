/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 05:11:55 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/24 22:18:17 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	move_to_next_room(t_room *src, t_room *dst)
{
	if (src->ant)
	{
		dst->ant = src->ant;
		src->ant = 0;
		// ft_printf("L%d-%s ", src->ant, src->name);
	}
}

void	moving(t_room *room)
{
	ft_printf("(%s)->", room->name);
	if (room->thread == NULL)
	{
		room->ant = 0;
		return ;
	}
	moving(room->thread);
	if ((room->thread->ant == 0) && (room->ant > 0))
		move_to_next_room(room, room->thread);
}

int		path_len(t_room *r)
{
	t_room	*tmp;
	int		i;

	tmp = r;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->thread;
	}
	return (i);
}

void	print_ant(t_lem *l)
{
	int		i;
	int		len;

	i = 1;
	len = path_len(l->room_list);
	ft_printf("len is %d !\n", len);
	while (i - len <= (l->ant - 2))// nb_room <= nb_ant -2
	{
		if (i <= l->ant)
		{
			l->room_list->ant = i;
			// ft_printf("\nL%d dans %s\n", i, l->room_list->name);
		}
		moving(l->room_list);
		i++;
		ft_printf("\n");
	}
}
