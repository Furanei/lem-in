/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 05:11:55 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/02 04:55:56 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	move_to_next_room(t_room *src, t_room *dst)
{
	dst->ant = src->ant;
	src->ant = 0;
	printf("L%d-%s ", dst->ant, dst->name);
}

void	moving(t_room *room)
{
	if (room->thread == NULL)
	{
		room->ant = 0;
		return;
	}
	if (room->thread->ant > 0)
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
		
	i = 1;
	len = path_len(l->room_list);
	while (i <= (l->ant + len))
	{	
		l->room_list->ant = i;
		moving(l->room_list);
		i++;
		printf("\n");
	}
}


// recherche dans room_list un ant le plus loin
// unr fois trouve, j'avance le ant
// j'essai d'avancer un 2eme
// 	si oui, repeat,
// 	si non, fin 
// print ant-room
// recommencer
