
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:58:44 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/21 20:52:54 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		check_ant(t_lem *l)// OK
{
	parse_comment(&*l);
	if (l->f & 0xFFFFFFFE || !(ft_isnumber(l->lmap[l->i],
	ft_strlen(l->lmap[l->i]))))// todo int ?
		ft_error("ERROR (ant_error)");
	if (!(l->ant = ft_atoi(l->lmap[l->i])))
		ft_error("ERROR (no_ant)");
	l->f += ANT;
}

int		check_room(t_lem *l)
{
	int i;

	i = 0;
	l->i++;
	while (1)
	{
		parse_comment(&*l);
		if (ft_strchr(l->lmap[l->i], '-'))
			break;
		if (l->lmap[l->i][0] == 'L')
			l->i++;
		else if (search_sharp(l) == 2)
		{
			parse_order(&*l);
		}
		else if (!room_count_word(l->lmap[l->i], ' '))
			ft_error_info(INFO, l->lmap[l->i]);
		else
			parse_room(&*l, 0);
		l->i++;
	}
	return (1);
}

void	malloc_ptr_pipe(t_lem *l)
{
	t_room		*tmp;

	tmp = l->room_list;
	while (tmp)
	{
		tmp->pipe = malloc(sizeof(void*) * l->nb_room);
		ft_bzero(tmp->pipe, sizeof(void*));
		tmp = tmp->next;
	}
}

void	check_error(t_lem *l)
{	
	check_ant(&*l);
	check_room(&*l);
	// ft_test_room_list(l->room_list);
	malloc_ptr_pipe(&*l);
	check_pipe(&*l);
	// ft_test_room_pipe(l->room_list);
}
