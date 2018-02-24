/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:37:39 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/24 22:16:11 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_test_room_list(t_room *rlst)///////
{
	t_room *tmp;

	tmp = rlst;
	ft_printf("(*rlst)->");
	while (tmp)
	{
		ft_printf("[%s]->", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
}

void	ft_test_room_pipe(t_room *rlst)///////
{
	t_room *tmp;
	int i;

	i= 0;
	tmp = rlst;
	ft_printf(" |\n");
	while (tmp)
	{
		i = 0;
		ft_printf("[%s]->", tmp->name);
		while (i < tmp->npipe)
		{
			ft_printf("<%s>", tmp->pipe[i]->name);
			i++;
		}
		if (tmp->spe & START)
			ft_printf("(start)");
		else if (tmp->spe & END)
			ft_printf("(end)");
		tmp = tmp->next;
		ft_printf("\n |\n");
	}
	ft_printf("NULL\n");
}
// le prblemme semble venir de l'enregirstrement du chemin dans L'ALGO