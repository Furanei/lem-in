/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 05:11:55 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/01 05:46:25 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_ant(t_lem *l)
{
	int i;
	t_room	*tmp;

	i = 1;
	tmp = l->room_list->thread;
	while (i <= l->ant)
	{
		tmp = l->room_list->thread;
		while (tmp)
		{
			printf("L%d-%s\n", i, tmp->name);	
			tmp = tmp->thread;
		}
		i++;
	}
}